#!/usr/bin/perl

use strict;
use warnings FATAL => 'all';

my $instructions_file = `cat Code/instructions.cpp` or die "Couldn't read instructions file.\n";
if ($instructions_file =~ /Instruction instructions\[\] = \{(.+?)\}/s) {
    my $instructions_block = $1;
    my $index = 0;
    my @rules;
    while ($instructions_block =~/INSTRUCTION\((.+?),.+?,\s*(\d+)\)/g) {
        my $arg_template = "";
        my $arg_value = "";
        if ($2 != 0) {
            $arg_template = $2 == 1 ? "{value}" : "{address}";
            $arg_value = $2 == 1 ? "\@ value`8" : "\@ address`16";
        }
        my $rule = sprintf("%-8s %-13s => 0x%02X %s", lc($1), $arg_template, $index, $arg_value);
        push(@rules, ($rule));
        $index++;
    }
    print "#ruledef {\n  " . join("\n  ", @rules) . "\n}\n";
} else {
    print "Couldn't find instruction block.\n";
}