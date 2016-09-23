#!/usr/bin/python
# -*- coding= latin-1 -*-

# program sort􏰀(input,􏰅 output)
# var
# a􏰅,b,􏰅c : integer􏰍

# begin 
#	readln􏰀(a􏰅,b,􏰅c)
#	􏰁􏰍if a 􏰎< b then
#		if b <􏰎 c then 
#			writeln􏰀(a􏰅,b,􏰅c)􏰁;
#		else if a 􏰎< c then
#			writeln􏰀(a,􏰅c,􏰅b)􏰁;
#		else
#			writeln􏰀(c,􏰅a,􏰅b)􏰁;
#	else	
#		if a 􏰎< c then
#			writeln􏰀(b,􏰅a,􏰅c);􏰁 
#		else if b <􏰎 c then
# 			writeln(􏰀b,􏰅c,􏰅a);
#  		else
#  			writeln(c,b,a);􏰁
# end.

def PrintVars(array, overallSize):
	string = "";
	for i in range(overallSize):
		string += array[i]
		if i != (overallSize - 1):
			string += ","
	return string

def ValueArrayCopy(array, overallSize):
	temp_array = range(overallSize)
	for i in range(overallSize):
		temp_array[i] = array[i]
	return temp_array

def rearrangeArray(array, level, i):
	temp = array[level]
	for j in range(i):
		array[level - j] = array[level - j - 1]
	array[level - i] = temp

# level starts from 1
# overallSize starts also from 1
def PascalSort(array, overallSize, level, tabs):
	if overallSize == level:
		print tabs + "writeln(" + PrintVars(array, overallSize) + ")"
	else:
		for i in range(level+1):
			tempArray = ValueArrayCopy(array, overallSize);
			if i == 0:
				print tabs + "if " + tempArray[level-1-i] + " < " + tempArray[level] + " then"
			elif i == level:
				print tabs + "else"
			else:
				print tabs + "else if " + tempArray[level-1-i] + " < " + tempArray[level] + " then"
			rearrangeArray(tempArray, level, i)
			PascalSort(tempArray, overallSize, level+1, tabs+"    ")


x = int(raw_input())
alphabet = ["a", "b", "c", "d", "e", "f"]
input_array = alphabet[0:x]
print "program sort(input, output);"
print "var"
print PrintVars(input_array,x) + ": integer;"
print "begin"
print "    readln(" + PrintVars(input_array, x) + ");"
PascalSort(input_array, x, 1, "")
print "end."

