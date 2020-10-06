#!/bin/bash

# echo "$@" #all args
# args=("$@")
# echo "$args"

# echo "$(wc -l file.txt)"

if [ $# -eq 0 ];then
	echo "Enter some parameters!"

else
	if [ -e $1 ] && [ -e $2 ];then
		echo "Lines in $1 = $(wc -l $1)"
		echo "Lines in $2 = $(wc -l $2)"
		echo""
		echo "Words in $1 = $(wc -w $1)"
		echo "Words in $2 = $(wc -w $2)"
		echo ""
		echo "Characters in $1 = $(wc -m $1)"
		echo "Characters in $2 = $(wc -m $2)"
	else
		echo "Files dont exist"
	fi
fi