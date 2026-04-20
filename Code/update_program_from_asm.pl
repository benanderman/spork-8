#!/usr/bin/perl

($asmPath, $functionName) = @ARGV;

$binaryArray = `customasm "$asmPath" -f hexcomma -p -q | tail -n +2049`;
chomp $binaryArray;

$programsCpp = `cat programs.cpp`;
$programsCpp =~s/($functionName\(.+?PROGMEM data\[\] = {\n)[^}]+(\n.+?};)/\1$binaryArray\2/s;

open($FILE, ">", "programs.cpp") or die "Couldn't open programs.cpp for writing: $!\n";
print $FILE $programsCpp;
close($FILE);