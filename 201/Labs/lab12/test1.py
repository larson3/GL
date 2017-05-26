def makeList(theList):
    while len(theList)<8:
        try:
            num=int(input("Enter an int: "))
            if num >=0:
                theList.append(num)
        except ValueError:
            print("")

def selectionSort(theList):
    startScan=0
    count=0
    size=len(theList)
    print(theList)
    while count<len(theList):
        minIndex=startScan
        minValue=theList[startScan]

        for i in range(startScan,size):
            if theList[i]<minValue:
                minValue=theList[i]
                minIndex=i
        theList[minIndex]=theList[startScan]
        theList[startScan]=minValue
        count+=1
        startScan+=1
        print(theList)

def main():
    theList=[]
    print("Enter 8 integers")
    makeList(theList)
    selectionSort(theList)
    
main()
