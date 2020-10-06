#!/bin/bash


read -p "Enter a Number: " num 

if [ $num -gt 0 ];then
	echo "$num is Postive"

elif [ $num -lt 0 ];then
	echo "$num is Negative"

else
	echo "$num is Zero"

fi