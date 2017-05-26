#File: lab4.py
#Author: John Larson
#Date: 2/24/13
#Section: 2
#Email: larson3@umbc.edu
#Description: Program will test if user input is a perfect number

import sys

def main():

    total = 0
#Get a positive number from the user
    
    uservariable = int(input("Please enter a positive integer: "))

#Test for negative number

    if uservariable <= 0:
        print("Please enter a positive integer next time")
        sys.exit()

    elif uservariable > 0:
        for i in range(1,uservariable):
            if uservariable % i == 0:
                total += i
        if uservariable == total:
            print("Perfect number!")
        else:
            print("Not a perfect number")
        
main()
