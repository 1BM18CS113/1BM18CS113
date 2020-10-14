echo "Enter one file to copy to other"
read file1
read file2

cat $file1
cat $file2
echo `cp $file1 $file2`
echo `cat $file2`
