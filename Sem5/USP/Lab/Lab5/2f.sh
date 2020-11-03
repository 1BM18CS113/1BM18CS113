#!/bin/bash

function Arithmetic()
{
	read -p "Enter a Two Numbers: " num1 num2
	echo "$num1 $num2"

    read -p "Choose operation: +,-,/,* " choice
    
    case $choice in
    	"+" )
		echo "$num1 + $num2="
    	echo "$num1 + $num2" | bc	;;
    	"-" )
		echo "$num1 - $num2="
		echo "$num1 - $num2" | bc	;;
		"*" )
   		echo "$num1 * $num2="
		echo "$num1 * $num2" | bc	;;
		"/" )
		echo "$num1 / $num2="
		echo "scale=2;$num1 / $num2" | bc	;;
		"%" )
		echo "$num1 % $num2="
		echo "scale=2;$num1 % $num2" | bc	;;
		* )
			echo "Wrong Choice!";;
    esac

}



function VowelOrConsonant()
{
	read -p "Enter a Character: " char
	if [[ $char == *[AEIOUaeiou]* ]];then
		echo "Vowel!"
	else
		echo "Consonant!"
	fi
}


echo "1.Arithmetic operations"
echo "2.Vowel Or Consonant"
read -p "Enter choice: " ch

if [ $ch -eq 1 ];then
	Arithmetic

elif [ $ch -eq 2 ];then
	
	VowelOrConsonant 

else
	echo "Wrong Choice!"
fi