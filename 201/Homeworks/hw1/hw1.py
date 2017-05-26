#File: hw1.py
#Author: John Larson
#Date: 2/8/2014
#Section: 2
#E-mail: larson3@umbc.edu
#Description:  This program will obtain a number and string from the user.  It will then apply several changes to the inputs, resulting in varying outputs.

import math

def main():

    #defining variables
    usernumber = 0
    remainder = 0
    cubed = 0
    logarithm10 = 0

    #asking for numerical input
    usernumber = float (input ("Please enter a positive whole number "))

    #asking for a string input
    userstring = str(input("Please enter a word containing 5 letters or more. " ))

    #display remainder
    remainder = usernumber % 3
    print("This is the remainder when divided by three0: ", remainder)

    #display cube
    cubed = usernumber ** 3
    print("This is your number cubed: ", cubed)

    #display log base 10
    logarithm10 = math.log10(usernumber)
    print("This is your number base 10 log: ")
    print("%.5f" %(logarithm10))

    #displaying string input
    print("This is the word you entered ", userstring)

    #displaying last three letters of string
    print ("These are the last three letters of your word ",userstring[-3:])

    #displaying the decimal ASCII value of the 3rd letter
    asciivalue = userstring[3:4]
    print ("This is the ASCII value of the 3rd letter of your word", ord(asciivalue))

    #changing all instances of the first letter to "@"
    print ("i am finished!".replace("i", "@"))

main()
