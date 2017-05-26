def selectionSort(theList):
    startScan=0
    count=0
    size=len(theList)
    
    while count<len(theList):
        minIndex=startScan
        minValue=theList[startScan]
        
        for i in range(startScan,size):
            
            
            if theList[i]<minValue:
                minValue=theList[i]
                minIndex=i

        theList[minIndex]=theList[startScan]
        theList[startScan]=minValue
        startScan+=1
        count+=1
        print(theList)

def makeList(theList):
    
    while len(theList)<8:
        
        try:
            num=int(input("Enter an int: "))
            if num>=0:
                theList.append(num)
                
        except ValueError:
            print("")


def main():
    theList=[]
    print("Enter 8 integers")
    makeList(theList)

    print("Sorting...")
    selectionSort(theList)
    print("After sort: ",theList)
main()
