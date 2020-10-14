#!/bin/bash

read -p "Enter Three Numbers: " num1 num2 num3

if [ $num1 -gt  $num2 ] && [ $num1 -gt $num3 ];then
	echo "$num1 is Greatest"

elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ];then
	echo "$num2 is Greatest"

else
	echo "$num3 is Greatest"

fi
