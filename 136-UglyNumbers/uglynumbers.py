uglyNumbers = list();
uglyNumbers.append(1);
for i in range(1499):
	x = uglyNumbers[0]
	uglyNumbers.remove(x)
	temp1 = 2*x
	temp2 = 3*x
	temp3 = 5*x
	temp = temp1
	j = 0
	while j < len(uglyNumbers):

		if uglyNumbers[j] > temp :
			uglyNumbers.insert(j, temp)
		elif uglyNumbers[j] < temp :
			j += 1
			continue

		if temp == temp1:
			temp = temp2
		elif temp == temp2:
			temp = temp3
		else:
			break

		j += 1


	if temp == temp1:
		uglyNumbers.append(temp)
		temp = temp2

	if temp == temp2:
		uglyNumbers.append(temp)
		temp = temp3

	if temp == temp3:
		uglyNumbers.append(temp)

	print uglyNumbers


ans = uglyNumbers[0]
print "The 1500'th ugly number is %d" % ans
	