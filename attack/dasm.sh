#!/bin/bash

if [[ $INFILE -eq '' ]];then
    INFILE='ctarget'
fi

gdb -nx -batch -ex "file $INFILE" -ex "disassemble $1"
