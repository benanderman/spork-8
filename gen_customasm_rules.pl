#!/usr/bin/perl

use strict;
use warnings FATAL => 'all';

my %name_map = (
    "REGA"         => "A",
    "REGB"         => "B",
    "REGC"         => "C",
    "PCNT"         => "PCnt",
    "MADR"         => "MAdr",
    "STCK"         => "Stack",
    "OUTA"         => "OutA",
    "SHFT"         => "Shift",
    "SWAP"         => "Swap",
    "IOA"          => "InOutA",
    "IOB"          => "InOutB",
    "PCNT_BSELECT" => "HighB",
    "MADR_BSELECT" => "HighB",
);

my %flags_mapping = (
    "UNCONDITIONAL" => "",
    "ZF|ZF_CF"      => "Z",
    "CF|ZF_CF"      => "C",
    "CF|NO_FLAGS"   => "NZ",
    "ZF|NO_FLAGS"   => "NC",
);

sub mappedName {
    my $name = shift;
    if (!defined $name) {
        return "";
    }
    if ($name =~ /^\d+$/) {
        return $name;
    }
    return $name_map{$name};
}

my $instructions_file = `cat Code/instruction_set.cpp` or die "Couldn't read instructions file.\n";
if ($instructions_file =~ /Instruction instructions\[\] = \{(.+?)\}/s) {
    my $instructions_block = $1;
    my $index = 0;
    my @rules;
    while ($instructions_block =~/    Instruction\(Instruction::Type::(\w+?),.*?FlagsMask::(\w+)(?:\s*\|.*FlagsMask::(\w+))?,\s*(CONST_(?:ZERO|ONE)\()?(\d)\)?(?:, (\w+))?(?:, (\w+))?(?:, (\w+))?/g) {
        my $arg_template = "";
        my $arg_value = "";
        my $flags1 = $2;
        my $flags2 = $3 ? "|$3" : "";
        my $flags_suffix = $flags_mapping{"$flags1$flags2"};
        my $inst = "$1$flags_suffix";
        my $data_bytes = $5;
        my $var1 = mappedName($6);
        my $var2 = defined $7 ? ", ".mappedName($7) : "";
        my $var3 = defined $8 ? ", ".mappedName($8) : "";
        my $vars = "$var1$var2$var3";
        my $zero_suffix = "  ";
        if (defined $4) {
            $data_bytes--;
            $zero_suffix = ($4 eq "CONST_ONE(") ? "01" : "00";
        }
        if ($data_bytes != 0) {
            $arg_template = $data_bytes == 1 ? "{value}" : "{address}";
            $arg_value = $data_bytes == 1 ? "\@ value`8" : "\@ address`16";
            if ($data_bytes == 3) {
                $arg_template = "{address} {value}";
                $arg_value = "\@ address`16 \@ value`8";
            }
        }
        my $rule = sprintf("%-14s %-20s %-20s => 0x%02X%s %-27s %s", $inst, $vars, $arg_template, $index, $zero_suffix, $arg_value, ($index & 1 << 4) ? "; Has 5th bit" : "");
        push(@rules, ($rule));
        $index++;
    }
    print "#ruledef {\n  " . join("\n  ", @rules) . "\n}\n";
} else {
    print "Couldn't find instruction block.\n";
}