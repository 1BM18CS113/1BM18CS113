#!/bin/bash

read -p "Enter n: " n

a=0
b=1
itr=0

echo "The Fibonacci series is : "

while [ $itr -lt $n  ]; do
	itr=$(echo "$itr + 1" | bc)
	echo -n "$a "
    fn=$((a + b))
    a=$b
    b=$fn
	
done

