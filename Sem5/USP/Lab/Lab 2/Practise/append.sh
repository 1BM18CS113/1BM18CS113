echo "Enter src and dest"
read src
read dest

echo "file 1 : "
cat $src
echo "File 2 : "
cat $dest

echo "After appending : dest is  "
`cat $src>>$dest`
cat $dest
