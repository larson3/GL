myList = [3,22,94,0,5,2,1,5,33,23,51,9,-1,7]
print(myList)
listSorted = False
while not listSorted:
	listSorted = True
	for i in range(0,len(myList)-1):
		if myList[i] > myList[i+1]:
			temp = myList[i+1]
			myList[i+1] = myList[i]
			myList[i] = temp
			listSorted = False
	print(myList)
