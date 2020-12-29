echo -n "Enter Filename: "
read file
vowel=0

for str in `cat $file`
do
  len=$(expr length $str)
  while [$len -gt 0]
  do
    ch=$(echo $str | cut -c $len)
    
    case $ch in
      ([aeiouAEIOU])vowel=$((vowel+1)) ;;
    esac
    len = $((len-1))
  done
done
echo "Vowel Count = "$vowel
