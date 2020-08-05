
def hanoi(a, c, b, n):
	if n == 1:
		print("move from {} to {}".format(a, c))
	else:
		hanoi(a, b, c, n-1)
		hanoi(a, c, b, 1)
		hanoi(b, c, a, n-1)
	return
	
	
	
#hanoi('a', 'c', 'b', 3)



print("########################$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$###################################################")


def gcd(m, n1):
	if(m==n1):
		print(m)
		return
	
	if m>n1:
		gcd(m-n1, n1)
	else:
		gcd(m, n1-m)
		

gcd(69,420)



print("########################$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$###################################################")


def partB():
	flag1 = 0
	a =[]
	key = 2
	n2 = int(raw_input("Enter length of array"))
	for i in range(n):
		a.append(int(raw_input()))
	
	l1 = 0, h1 = n2-1, m1=0, m2
	
	while l1<=h1:
		m1= l1+h1 // 2
		
		ifa[m1] == key:
			m2=m1
			break
		elif a[m1] > key:
			h1 = m1-1
		else:
			l1 = m1+1		
	
	while a[m1] == key or a[m2] == key:
		if m1 == key:
			m1 -=m1
		if m2 == key:
			m2 -=m2
		
print(m1, m2, m2-m1)
	
	
