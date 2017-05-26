#File: hw7.py
#Author: John Larson
#Date: 3/26/14
#Section: 2
#Email: larson3@umbc.edu
#Description: This file contains a code which will import the contents of a text file and convert each character to its ASCII value in a user selected base.  It will write the output to a new file.

#getFile() will run the given file title and return the content of the file, then it will turn any alphanumeric characters into their ASCII value
#Input: user input file name
#Output: File content

def getFile(fileName):
    fileList = []
    #opening file
    newFile = open(fileName, "r")
    #looping through values in file and replacing with ASCII values and ".."
    for currentLine in newFile:
        for i in currentLine:
            #checking to make sure value is alphanumeric
            if ((ord(i)>= 48 and ord(i)<=57) or (ord(i) >= 65 and ord(i)<=90) or (ord(i)>= 97 and ord(i)<=122)):
                #writing the ASCII value to the list or ..
                fileList.append(ord(i))
            else:
                fileList.append("..")   
    return(fileList)
            
    

#performBaseCalc(importFile) will take in a list of ASCII values, it will then prompt the user for a base and change the list into numbers of the specified base
#Input: file name
#Output: string containing the contents of the file in ASCII with a change of base

def whichBaseCalc(importFile):
    validBase = False
    #begin sentinel loop
    while validBase == False:
        try:
            whichBase = int(input("Enter a base between 2 and 9: "))
            if whichBase >= 2 and whichBase <= 9:
                validBase = True
        #checking to make sure entry is an integer
        except ValueError:
            validBase = False
    return whichBase
    
#conversion(userNum, whichBase) will take in a user base and a value, it will then perform a base change to the value based on the chosen base, this function is called within the performBaseCalc function
#Input: value and chosen base
#Output: value changed to the chosen base

def conversion(userNum, whichBase):
    convertedValue = ""
    tempList = []
    #start loop until division brings the number below 1
    while (userNum != 0):
        try:
            #loop through each value and return the base number
            newBaseValue = int(userNum) % int(whichBase)
            #lower the usernum so we know when to end the loop
            userNum = int(userNum) // int(whichBase)
            tempList.append(int(newBaseValue))
        #exception for the ValueError when the function tries to convert ".."
        except ValueError:
            tempList.append("..")
            userNum = 0
    #reversing the list, and adding reversed list to the main list
    for num in (reversed(tempList)):
        convertedValue = convertedValue + str(num)
    return convertedValue

#performBaseCalc(valueList,whichBase) will take in a user base and value list, it will then perform a base change to the list based on the chosen base
#Input: List of values and chosen base
#Output: List of values changed to the chosen base

def performBaseCalc(valueList,whichBase):
    
    currentValue = ""
    newList = []
    #running a for loop and calling the conversion function
    for i in valueList:
        currentValue = conversion(i, whichBase)
        #putting the converted value onto the new list
        newList.append(currentValue)
    return newList

#writeToNewFile(baseCalculation) will take in the converted string and write it to a new file
#Input: Converted string
#Output: New file containing converted string

def writeToNewFile(valueList,whichBase,fileName):
    spaceCount = 0
    #creating a name for the new file
    outName = str(whichBase) + "_" + fileName
    #creating and opening our new file
    outputFile = open(outName, "w")
    #looping through the string and writing its contents to the new file
    for i in valueList:
        outputFile.write(str(i))
        outputFile.write(" ")
        spaceCount +=1
        #printing a blank line every 5 values
        if spaceCount % 5 == 0:
            outputFile.write("\n")
    #making things look nicer
    outputFile.write("\n")
    outputFile.close()

    return()

def main():
    
    print("This is a filter program that will convert your text file into ASCII value")
    validFile = False
    #start verification loop
    while validFile == False:
        try:
            whichFile = input("Enter the name of the file: ")
            #opening the selected file
            open(whichFile, "r")
            validFile = True
        #exception for if the entry is not a string
        except FileNotFoundError:
            validFile = False
    
    #calling a function to change list to ASCII value
    newList = getFile(whichFile)
    
    #calling function to prompt the user to select a new base
    chosenBase = whichBaseCalc(newList)
    
    #calling function to convert list to new base
    convertedList = performBaseCalc(newList,chosenBase)
    
    #calling function to write converted list to a new file
    writeToNewFile(convertedList,chosenBase,whichFile)
    
    #imforming the user that the program was successful and where to find the program
    print("Done.  Use cat to see the file: "+str(chosenBase)+"_"+str(whichFile))


main()
