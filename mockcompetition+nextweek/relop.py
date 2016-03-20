x = int(input())

for i in range(x):
	y,z = input().split()
	if int(y) > int(z):
		print(">")
	elif int(y) < int(z):
		print("<")
	else:
		print("=")
