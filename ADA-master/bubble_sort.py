import timeit, time

def bubble(arrray):	
	
	n = len(array)
	for i in range(n):
		for j in range(n-i-1):
			if array[j] > array[j+1]:
				temp = array[j]
				array[j] = array[j+1]
				array[j+1] = temp
		#print(array)
	return array
	

array = []
for i in range(10000, 0, -1):
	array.append(i)
	
seconds = time.time()	
res = bubble(array)
end = time.time()

print(end - seconds)
#print(res)








