m, n=int(input("Enter range\n")), int(input())
# print([i for i in range(m, n+1) if (i%10 != i//10)])

def checkDigits(n):
  digit_count = {}
  while n!=0:
    digit = n%10
    if digit not in digit_count:
      digit_count[digit] = 1
    else:
      digit_count[digit] += 1
    n//=10
  for key, value in enumerate(digit_count.values()):
    if value > 1:
      return False
  return True


for i in range(m, n+1):
  if checkDigits(i):
    print(i)