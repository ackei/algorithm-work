listofDivisions = [1,2,4,10,20,40,100,200,400,1000,2000]
numofDivisions = []

for i in range(6001):
	numofDivisions.append([0,0,0,0,0,0,0,0,0,0,0,0])
for j in range(12):
	numofDivisions[0][j] = 1

for i in range(1,6001):
	for j in range(1,12):
		numofDivisions[i][j] = numofDivisions[i][j-1] + numofDivisions[i - listofDivisions[j-1]][j]

while 1:
	x = float(raw_input())
	x /= 0.05
	if x == 0:
		break
	print numofDivisions[int(x)][11]