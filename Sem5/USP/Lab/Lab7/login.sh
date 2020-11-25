#! /bin/sh
if [ $# -eq 0 ]
then
echo "No command line argument passed"
exit
fi
while [ $1 ]
do
cat /etc/passwd | cut -d ":" -f1 | grep "^$1" > temp
ck=`cat temp`
if [ "$ck" != "$1" ]
then
echo "ERROR:$1 is an invalid login name"
else
echo "Home Directory for $1 is"
echo `cat /etc/passwd | grep "^$1" | cut -d ":" -f6`
fi
shift
done
