def getFile():
    loop = True
    while loop:
        fileName = input("Enter the name of the file: ")
        try:
            theFile = open(fileName, "r")
            return theFile
        except FileNotFoundError:
            loop = True

def makeList(theFile,nameList,numList):
    for currentLine in theFile:
        name = currentLine.split()[0]
        name = name.lower()
        nameList.append(name)
        num = currentLine.split()[1]
        numList.append(num)        
    return

def changeToDict(nameList,numList,userDict):
    count = 0
    while count != len(numList):
        userDict[nameList[count]] = numList[count]
        count+=1
    return userDict
           
def theAvg(numList):
    total = 0
    for num in numList:
        total += int(num)
    avg = int(num)//len(numList)
    return avg


def main():
    numList = []
    nameList = []
    userDict = {}
    programLoop = True
    theFile = getFile()
   
    makeList(theFile,nameList,numList)
    
    theDict = changeToDict(nameList,numList,userDict)
    
    while programLoop:
        userChoice = input("Enter 1 to see the score, 2 to change the grade, 3 to quit: ")
        if userChoice == "1":
            whichName = input("Enter a name: ")
            whichName = whichName.lower()
            if whichName in nameList:
                average = theAvg(numList)
                if int(userDict[whichName]) >= average:
                    print("The score is " +userDict[whichName]+ " which is above average")
                else:
                    print("The score is " +userDict[whichName]+ " which is below average")  
            else:
                print("No such name in list")
        elif userChoice == "2":
            whichName = input("Enter a name: ")
            whichName= whichName.lower()
            if whichName in nameList:
                newScore = (input("Enter a number between 0 and 100"))
                if int(newScore) >= 0 and int(newScore) <=100:
                    userDict[whichName] = newScore
                else:
                    print("Not in range")
            else: 
                print("No such name")
                
        elif userChoice == "3":
            print("Thank you for using this program")
            programLoop = False
        else:
            programLoop = True
    
main()
    
