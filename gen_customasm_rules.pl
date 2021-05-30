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
    "OUTB"         => "OutB",
    "SWAP"         => "Swap",
    "INPA"         => "InA",
    "INPB"         => "InB",
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
    while ($instructions_block =~/Type::(\w+?),.*?FlagsMask::(\w+)(?:\s*\|.*FlagsMask::(\w+))?,\s*(\d)(?:, (\w+))?(?:, (\w+))?(?:, (\w+))?/g) {
        my $arg_template = "";
        my $arg_value = "";
        my $flags1 = $2;
        my $flags2 = $3 ? "|$3" : "";
        my $flags_suffix = $flags_mapping{"$flags1$flags2"};
        my $inst = "$1$flags_suffix";
        my $data_bytes = $4;
        my $var1 = mappedName($5);
        my $var2 = defined $6 ? ", ".mappedName($6) : "";
        my $var3 = defined $7 ? ", ".mappedName($7) : "";
        my $vars = "$var1$var2$var3";
        if ($data_bytes != 0) {
            $arg_template = $data_bytes == 1 ? "{value}" : "{address}";
            $arg_value = $data_bytes == 1 ? "\@ value`8" : "\@ address`16";
            if ($data_bytes == 3) {
                $arg_template = "{address} {value}";
                $arg_value = "\@ address`16 \@ value`8";
            }
        }
        my $rule = sprintf("%-14s %-20s %-20s => 0x%02X %s", $inst, $vars, $arg_template, $index, $arg_value);
        push(@rules, ($rule));
        $index++;
    }
    print "#ruledef {\n  " . join("\n  ", @rules) . "\n}\n";
} else {
    print "Couldn't find instruction block.\n";
}