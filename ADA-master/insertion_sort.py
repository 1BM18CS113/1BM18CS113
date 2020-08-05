def ins_sort(array):
	
	for i in range(1, len(array) - 1):
		j = array[i+1]
		k = i
		while j<array[k] and k>=0:
			array[k+1] = array[k]
			k -= 1
		array[k+1] = j
		
	return array
		



array = [10, 20, 5, 25, 30, 7, 1, 1]
#print(ins_sort(array))





'''There is one meeting room in a firm. There are N meetings in the form of (Si, Fi) where Si is the start time of meeting i and Fi is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers'''


si = [1, 2, 3, 3, 4, 5, 5]
fi = [6, 4, 4, 5, 5, 8, 6]

si_fi = [fi[i] - si[i] for i in range(len(si))]

'''print(si_fi)
print(si)
print(fi)'''

def meeting(si, fi, si_fi):
	for i in range(1, len(si_fi) - 1):
		j = si_fi[i+1]
		a = si[i+1]
		b = fi[i+1]
		
		k = i
		while j<si_fi[k] and k>=0:
			si_fi[k+1] = si_fi[k]
			si[k+1] = si[k]
			fi[k+1] = fi[k]
			k -= 1
		si_fi[k+1] = j
		si[k+1] = a
		fi[k+1] = b
		
	#print(si_fi)
	print(si)
	print(fi)


meeting(si, fi, si_fi)


