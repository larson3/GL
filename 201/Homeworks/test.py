def main():

	list = []
	list.append(1)
	list.append(1)
	list.append(2)
	list.append(2)
	list.append(2)
	list.append(2)
	list.append(2)
	list.append(2)
	list.append(2)
	list.append(3)
	list.append(3)
	list.append(3)
	list.append(3)
	list.append(3)
	highCount=0
	length = len(list)
	count = 0
	#num = list[0]
	for currentNum in range (1,length):
		num = list[currentNum-1]
		num1 = list[currentNum]
		if num == num1:
			count+=1
			#print(list[currentNum])
		else:
			if count>highCount:
				highCount = count
			count = 0
			print(highCount)

	print(highCount+1)
	
main()