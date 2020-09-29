echo "Enter a and b"
read a b
ad=`expr $a + $b`
sb=`expr $a - $b`
mt=`expr $a \* $b`
dv=`expr $a / $b`
echo "ADDITION:  $ad"
echo "SUBTRACTION: $sb"
echo "MULTIPLICATION: $mt"
echo "DIVISION: $dv"

