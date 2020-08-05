import timeit, time


def selection_sort(array):
	
	min_index = 0
	temp =0;
	
	for i in range(len(array)):

		min = array[i]
		min_index = i
		
		for j in range(i, len(array)):
			if array[j] < min:
				min = array[j]
				min_index = j 
		
		
		
		temp = array[min_index]
		array[min_index] = array[i]
		array[i] = temp
		
		
		
		
	return array
		
		
array = []		
for k in range(100):
	array.append(k)
	



seconds = time.time()
selection_sort(array)
end = time.time()

print(end - seconds)



















# part b

def printt(array, k):
	min_index = 0
	temp =0;
	
	for i in range(k):

		min = array[i]
		min_index = i
		
		for j in range(i, len(array)):
			if array[j] > min:
				min = array[j]
				min_index = j 
		
		
		
		temp = array[min_index]
		array[min_index] = array[i]
		array[i] = temp
		

	#for ii in range(k):
		#print(array[ii])
		
	
		
sec1 = time.time()
printt(array, 3)
end1 = time.time()


print(end1 - sec1)









