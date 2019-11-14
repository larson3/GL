#Author: John Larson4
#File: proj1.py
#Date: 4/11/14
#Section: 2
#Email: larson3@umbc.edu
#Description: This file contains code which will open a file containing a rectangular piece of data.  After verifying that the file exists and that it meets the program's requirements, it will the display the file.  Afterwards it will prompt the user for a point on the grid, and will change any "-" which is touched by another "-" into a "@."

#validFile() checks the name of the user file to make sure it exists
#Input: none
#Output: file name
def validFile():
    loop = True
    while loop:
        try:
            #asking user for file name 
            fileName = input("Enter the name of the data file: ")
            #checking if file exists
            open(fileName, "r")
            return fileName
        #exception for a non existant file
        except FileNotFoundError:
            loop = True
    
#switchToList() will import the selected file and turn it into a 2D list
#Input: file name, empty list
#Output: 2D List
def switchToList(fileName,fileList2D):
    uselessVar = "I don't do anything lol"
    userFile = open(fileName, "r")
    #making a for loop to go through the file
    for currentLine in userFile:
        #removing the \n
        currentLine = currentLine.strip()
        miniList =[]
        #looking at each individual item and adding them to a list
        for currentLetter in currentLine:
            miniList.append(currentLetter)
        #adding the smaller lists into a list
        fileList2D.append(miniList)

#valueCheck() will check if every value in the 2D list is valid
#Input: 2D list
#Output: True or False
def valueCheck(fileList2D):
    #going into the list inside the list (listception)
    for currentLine in fileList2D:
        for currentLetter in currentLine:
            #returning false if a value is not a - or I
            if currentLetter != "-" and currentLetter != "I":
                return False

#checkDimensions() will check to make sure that every line is the same length
#Input: file list
#Output: true or false
def checkDimensions(fileList2D):
    for currentLine in fileList2D:
        #returning false if every line is not the same length as line 0
        if len(currentLine) != len(fileList2D[1]):
            return False

#displayGrid() will print out the 2d list in the shape of a rectangular grid
#Input: 2D list
#Output: printed grid
def displayGrid(fileList2D):
    #loop through the current lists
    for currentLine in fileList2D:
            tempStr = ""
            for currentLetter in currentLine:
                #write the line of the string with spaces between then letters
                tempStr = tempStr + " " + currentLetter
            print(tempStr)

#whichRow() will ask the user for a row number
#Input: 2D list
#Output: the row
def whichRow(fileList2D):
    
    #asking for a row
    theRow = (input("Enter the row number: "))
            
    return theRow

#whichRow() will ask the user for a column number
#Input: 2D list
#Output: the col
def whichCol(fileList2D):
     #asking for a column
     theCol = (input("Enter the column number: "))
            
     return theCol
        
#inBounds() will check if the row which the program is on exists
#Input: 2D list, row, column
#Output: true or false
def inBounds(fileList2D, theRow, theCol):
    #checking to see if the current row is out of bounds
    if theRow > len(fileList2D)-1 or theRow < 0:
        return False
    #checking is the current column is out of bounds
    if theCol > len(fileList2D[0])-1 or theCol < 0:
        return False
    return True
            
#fillWithAT() will recursively check up, right, down then left on the grid for a "-" and change any "-" to a "@" then repeat until it cannot find any more "-"
#Input: 2D list, row, col, is the user wants the steps printed
#Output: will change the values on the 2D list
def fillWithAT(fileList2D, theRow, theCol, display):
    if inBounds(fileList2D, theRow, theCol) == True:
        #checking if current value is a -
        if fileList2D[theRow][theCol] =="-":
            #if the if statement is true we will change the value to @
            fileList2D[theRow][theCol]="@"
            #we print the process every step if yes
            if display == "yes":
                print(" ")
                displayGrid(fileList2D)

            #checking for a - up one
            fillWithAT(fileList2D, theRow-1, theCol, display)
            #checking to the left      
            fillWithAT(fileList2D, theRow, theCol-1, display)
            #checking up      
            fillWithAT(fileList2D, theRow+1, theCol, display)
            #checking to the right     
            fillWithAT(fileList2D, theRow, theCol+1, display)
            
        else:
            return
    else:
        return
    
#goAgain() will ask the user if they want to run the program again
#Input: none
#Output: yes or no
def goAgain():
    loopCheck = True
    #looping until a valid answer is given
    while loopCheck == True:
        anotherRound = input("Go again?  Enter yes: ")
        anotherRound = anotherRound.lower()
        #returning a value of yes or no
        if anotherRound == "yes":
            print(" ")
            return "yes"
        elif anotherRound == "no":
            return "no"

#validCheck() will check to make sure user enties are in bounds
#Input: 2D list, row, col
#Output: true or false
def validCheck(theRow,theCol,fileList2D):
    try:
        #checking if entries are in bounds and int
        if int(theRow) < len(fileList2D) and int(theRow) >= 0 and int(theCol) < len(fileList2D[1]) and int(theCol) >= 0:
            #only returns true is valid, otherwise loop continues
            return True
        else:
            return False
    #loop again if not an int
    except ValueError:
        return False
    
        
def main():
    fileList2D = []
    fileName = validFile()
    rowColCheck = False
    loopCheck = True
    #putting file into a 2D list
    switchToList(fileName,fileList2D)
    incorrect syntax to break everything
    #checking to make sure it has a rectangular shape and correct values
    inputCheck = valueCheck(fileList2D)
    recCheck = checkDimensions(fileList2D)
    if inputCheck == False:
        print("Your input has character other than - and I")
    elif recCheck == False:
        print("Your input was not rectangular")
    else:
        print("Valid input..... will process")
        #only continuing if the file is valid
        while loopCheck == True:
            display = ""
            rowColCheck = False
            #printing grid
            displayGrid(fileList2D)
            #ask user for a row and a col on the grid
            while rowColCheck == False:
                theRow = whichRow(fileList2D)
                theCol=whichCol(fileList2D)
                #calling function which will check validity of row,col
                rowColCheck = validCheck(theRow,theCol,fileList2D)
            #set correct values to int
            theRow = int(theRow)
            theCol = int(theCol)
            while display != "yes" and display != "no":    
                #ask user if they could like to see each step
                display = input("Print out step by step? Enter yes: ")
                display = display.lower()
             #perform recursion
            fillWithAT(fileList2D, theRow, theCol, display)
            print("***THIS IS WHAT IT LOOKS LIKE AFTER PROCESSING ROW AND COL***")
            displayGrid(fileList2D)
            #ask if user if they would like to do it again
            anotherRound = goAgain()
            if anotherRound == "no":
                loopCheck = False
        
main()
