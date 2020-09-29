#!/bin/bash
file=file.txt
lines=$(wc -l file.txt)
characters=$(wc -c file.txt)
words=$(wc -w $file)


echo "characters = $characters"
echo "lines =  $lines"
echo "words = $words"

echo "characters = $characters lines =  $lines words = $words" > test.txt
cat test.txt