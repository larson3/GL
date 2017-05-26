#File: hw5.py
#Author: John Larson
#Date: 3/5/14
#Section: 2
#Email: larson3@umbc.edu
#Description:  This file conatined python code which will convert a base 10 number into a number base 2, 8 or 16 depending on the user's choice.  Proram ends if the user enters "stop".



#Function: switchBinary
#Converts a base 10 integer into base 2
#Input: One unsigned integer
#Output: Previous integer converted to base 2
def switchBinary(userInput):
    binaryList = []
    binaryString = ("")
    binaryNumber = 0

    #set for loop
    while userInput != 0:

        #Obtain remainder of userInput divided by 2
        binaryNumber =  userInput % 2

        #Decrease userInput by factor of 2
        userInput = userInput // 2
        binaryList.append(binaryNumber)

    #Run for loop and add every value of the list into the front of the string
    for i in binaryList:
        binaryString = str(i) + binaryString
    print(binaryString)

#Function: switchOctal
#Converts a base 10 integer into base 8
#Input: One unsigned integer
#Output: Previous integer converted to base 8

def switchOctal(userInput):
    octalList = []
    octalString = ("")
    octalNumber = 0

    #set for loop
    while userInput != 0:

        #Obtain remainder of userInput divided by 2
        octalNumber =  userInput % 8

        #Decrease userInput by factor of 2
        userInput = userInput // 8
        octalList.append(octalNumber)

    #Run for loop and add every value of the list into the front of the string
    for i in octalList:
        octalString = str(i) + octalString
    print(octalString)

def switchHex(userInput):
    hexList = []
    hexString = ("")
    hexNumber = 0
    testNumber = 0
    convertedHex = 0

    #set for loop
    while userInput != 0:

        #Obtain remainder of userInput divided by 2
        hexNumber =  userInput % 16

        #Decrease userInput by factor of 2
        userInput = userInput // 16
        hexList.append(hexNumber)

    #Convert number over 10 into ASCII 0 + differece between number and 10
    for i in hexList:
        testNumber = i - 10

        #test if number is greater than 10
        if testNumber >=0:

            #10 is ASCII "A" and add 1 for every number between 10 and i
            convertedHex = chr(ord("A") + testNumber)
            hexString = convertedHex + hexString
        else:
             hexString = str(i) + hexString
    print(hexString)



def main():
    
    #Define variables
    unsignedInteger = 0
    userBase = 0
    baseCheck = 0

    #Display Greeting
    print("This program will convert a base 10 integer into another base")

    #Set while loop
    while unsignedInteger != "stop":

        #Gather user input
        try:
            baseCheck = 0
            unsignedInteger = input("Enter an unsigned integer: ")

            #Check for an integer
            unsignedInteger = int(unsignedInteger)

            #Check for a negative
            if unsignedInteger > 0:

                #Looping back if user's input is wrong
                while baseCheck == 0:
                    userBase = input("B for binary, O for octal, H for hexidecimal: ")
                #Call different functions based on userBase
                    if (userBase == "b") or (userBase == "B"):
                        switchBinary(unsignedInteger)
                        baseCheck = 1
                    elif (userBase == "o") or (userBase == "O"):
                        switchOctal(unsignedInteger)
                        baseCheck = 1
                    elif (userBase == "h") or (userBase == "H"):
                        switchHex(unsignedInteger)
                        baseCheck = 1
                    else:
                        print("Invalid Choice!")
                    print("--------------")

        #Error check for a non-integer and capitalised "stop"    
        except ValueError:
            try:
               unsignedInteger =  unsignedInteger.lower()
            except ValueError:
                print("")
    print("Thank you for using this program")    
                
main()
