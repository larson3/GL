#File: hw6.py
#Author: John Larson
#Date: 3/23/14
#Section: 2
#Email: larson3@umbc.edu
#Description: This file contains python code which will convert a base 2, 8 or 16 string  into a base 10 integer.

#isBase2() checks the given string and returns "True" if string is in base 2
#Input: User number in base 2
#Output: True/False
def isBase2(base2):
    base2Loop = 0
    returnIndicator = 0
    #For loop to check each value of string
    for i in base2:
        #Sets variable to true if 1 or 0 and keeps looping
        if i == "0" or i == "1":
            returnIndicator = 1
        #If not 1 or 0 ends loop and returns false
        else:
            return False
    #if all 0's and 1's then the function will return True
    if returnIndicator == 1:
        return True

#isBase8() checks the given string and returns "True" if string is in base 8
#Input: User number in base 8
#Output: True/False

def isBase8(base8):
    base8Loop = 0
    returnIndicator = 0
    #For loop to check each value of string
    try:
        for i in base8:
            #Sets variable to true if between 0 and 7 and keeps looping
            if int(i) >= 0 and int(i) <= 7:
                returnIndicator = 1
            #If not between 0 and 7 ends loop and returns false
            else:
                return False
            #if all between 0 and 7 then the function will return True
        if returnIndicator == 1:
            return True
    #exception for value error
    except ValueError:
        return False

#isBase16() checks the given string and returns "True" if string is in base 16
#Input: User number in base 16
#Output: True/False

def isBase16(base16):
    base16Loop = 0
    returnIndicator = 0
    #capitalize the any letters
    base16 = base16.upper()
    #For loop to check each value of string
    for i in base16:
        #Sets variable to true if between 0 and 9 and keeps looping
        try:
            if int(i) >= 0 and int(i) <= 9:
                #will return true is entire string is in range
                returnIndicator = 1
            #If not between 0 and 9 ends loop and returns false
            else:
                return False
        #exception for value error
        except ValueError:
            if ord(i) >= 70 or ord(i) <= 64:
                return False
            else:
                returnIndicator = 1
    #if all in range then the function will return True
    if returnIndicator == 1:
        return True


#base2TO10() takes input of base 2 and returns integer of base 10
#Input: user number in base 2
#Output: user number in base 10 

def base2TO10(base2):
    base10Total = 0
    #finding length of string
    lengthBase2 = len(str(base2))
    #starting loop to add values
    for i in str(base2):
        lengthBase2 = lengthBase2 - 1
        #adding previous value to the product of i and the string length - 1
        base10Total = base10Total + (int(i) * 2**lengthBase2)
    return base10Total

#base8TO10() takes input of base 8 and returns integer of base 10
#Input: user number in base 8
#Output: user number in base 10

def base8TO10(base8):
    base10Total = 0
    #finding length of string
    lengthBase8 = len(str(base8))
    #starting loop to add values
    for i in str(base8):
        lengthBase8 = lengthBase8 - 1
        #adding previous value to the product of i and the string length - 1
        base10Total = base10Total + (int(i) * 8**lengthBase8)
    return base10Total

#base16TO10() takes input of base 16 and returns integer of base 10
#Input: user number in base 16
#Output: user number in base 10

def base16TO10(base16):
    base10Total = 0
    #making the string's letters captial
    base16 = base16.upper()
    #finding length of string
    lengthBase16 = len(str(base16))
    #starting loop to add values
    for i in str(base16):
        lengthBase16 = lengthBase16 - 1
        #adding previous value to the product of i and the string length - 1
        try:
            base10Total = base10Total + (int(i) * 16**lengthBase16)
        except ValueError:
            base10Total = base10Total + (ord(i) - 55) * (16**lengthBase16)
    return base10Total


        

def main():
    baseOption = 1
    base2 = ""
    base8 = ""
    base16 = ""
    loopCheck = False
    summary2List = []
    summary8List = []
    summary16List = []
    newBase = 0
    
    #print greeting
    print("This program will convert a base 2, base 8 or base 16 number into base 10")
    #set loop until user enters 0
    while baseOption != 0:
        try:
            baseOption = int(input("Enter 2 for base 2\nEnter 8 for base 8\nEnter 8 for base 8\nEnter 0 to stop: "))
            #begin switch from binary
            if baseOption == 2:
                loopCheck = False
                #Set up while loop to repeat input if entry is not binary
                while loopCheck == False:
                    base2 = input("Enter a base 2 number: ")
                    #calling isBase2 function
                    loopCheck = isBase2(base2)
                    if loopCheck == True:
                        #calling function to turn to base 10
                        newBase = base2TO10(base2)
                        #display results
                        print("Base 2 number: ", base2, "is base 10 number: ", newBase)
                        #save results to summary list
                        summary2List.append(base2)
                        summary2List.append(newBase)
            elif baseOption == 8:
                loopCheck = False
                #Set up while loop to repeat input if entry is not binary
                while loopCheck == False:
                    base8 = input("Enter a base 8 number: ")
                    #calling isBase8 function
                    loopCheck = isBase8(base8)
                    if loopCheck == True:
                        #calling function to turn to base 10
                        newBase = base8TO10(base8)
                        #display results
                        print("Base 8 number: ", base8, "is base 10 number: ",newBase)
                        #save results to summary list
                        summary8List.append(base8)
                        summary8List.append(newBase)

            elif baseOption == 16:
                 loopCheck = False
                #Set up while loop to repeat input if entry is not binary
                 while loopCheck == False:
                     base16 = input("Enter a base 16 number: ")
                     #calling isBase16 function
                     loopCheck = isBase16(base16)
                     if loopCheck == True:
                         #calling function to turn to base 10
                         newBase = base16TO10(base16)
                         #display results
                         print("Base 16 number: ", base16, "is base 10 number: ",newBase)
                         #save results to summary list
                         summary16List.append(base16)
                         summary16List.append(newBase)

            elif baseOption == 0:
                #displaying summary
                print("Summary \n----------------")
                while len(summary2List) != 0:
                    #displaying results of base 2 conversions
                    print("Base 2 number: ", summary2List[0], "--->", summary2List[1])
                    del summary2List[0]
                    del summary2List[0]
                    #results of base 8 conversion
                while len(summary8List) != 0:
                    print("Base 8 number: ", summary8List[0], "--->", summary8List[1])
                    del summary8List[0]
                    del summary8List[0]
                    #results of base 16 conversion
                while len(summary16List) != 0:
                    print("Base 16 number: ", summary16List[0], "--->", summary16List[1])
                    del summary16List[0]
                    del summary16List[0]
                    
                print("End of program")
            else:
                print("Invalid choice")
        except ValueError:
            print("Invalid choice")
        print("")
main()
