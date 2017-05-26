#File: hw2.py
#Author: John Larson
#Date: 2/13/14
#Section: 2
#E-mail: larson3@umbc.edu
#Description: Performs simple mathematical operations based on user inputs

def main():

    #declare variables
    num1 = 0
    num2 = 0
    num3 = 0
    operator1 = 0
    operator2 = 0
    
    #Describe program to user
    print("This program will do simple calculations.")

    #obtain user input
    num1 = int(input("Please enter the first operand: "))
    num2 = int(input("Please enter the second operand: "))
    operator1 = input("Please enter a mathematical operation: ")
    operator2 = str.lower(operator1)

    #displaying user inputs
    print("Your first integer is: ", num1)
    print("Your second integer is: ", num2)

    #making decisions based on input
    if operator2 == "add":
       num3 = num1 + num2
       print("The operation is ", operator1)
       print("The result is ", num3)

    elif operator2 == "subtract":
        num3 = num1 - num2
        print("The operation is ", operator1)
        print("The result is ", num3)

    elif operator2 == "multiply":
        num3 = num1 * num2
        print("The operation is ", operator1)
        print("The result is ", num3)

    elif operator2 == "divide":
        if num2 != 0:
            num3 = num1 / num2
            print("Your operator is", operator1)
            print("The result is", int(num3))
        
        else:
            print("Division by zero is not allowed")

    else:
        print(operator1 + " is not a valid operator")

    print("----------")

    #dispaying final messages
    if num1 and num2 > 0:
        print("Both operands were positive")
    
    if num1 and num2 < 0:
       print("Both operands were negative")

    if num3 >= 100:
        print("The result has three or more digits in it")
main()
