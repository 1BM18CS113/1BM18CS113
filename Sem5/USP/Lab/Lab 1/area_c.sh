#!/bin/bash

# echo  "Enter radius: \c"
# read r
# $pi=3.142
# area=echo "scale=3.142 \* $r \* $r" |bc

# echo "Area of circle: $area"


echo "Enter radius: "
read r

area=$(echo '3.1545 \* $r \* $r' | tr -d $'\r' | bc) 
echo "$area"