#File: lab2.py
#Written by: John Larson
#Date: 2/10/2014
#Section: 2
#Email: larson3@umbc.edu
#Description: Lab 2, i/o and Math operators

def main():

    #Prompt for 3 imput values
    Value1 = input("Please type a number.")
    Value2 = input("Another number.")
    Value3 = input("One more please.")
    #convert the strings into integers
    Value1 = int(Value1)
    Value2 = int(Value2)
    Value3 = int(Value3)
    #Perform mathematical operations
    Value1 = Value1 ** 2
    Value4 = Value2 + Value3
    #Print the totals
    print("This is your first value squared: ",Value1)
    print("This is the sum of your first and second numbers: ", Value4)
main()
