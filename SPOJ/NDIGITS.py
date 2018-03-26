t = int(input());

i = 0

while i < t:
	i += 1
	n = int(input())
	if(n == 1):
		print(10)
	else:
		print(9 * pow(10, n - 1))