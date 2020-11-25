#!/bin/bash

read -p "Enter names of File1 and file2: " f1 f2

rm file3.txt
touch file3.txt 
head -n 5 $f1 > file3.txt 
head -n 15 $f2  | tail -n 8 >> file3.txt
echo "Created file3.txt"
