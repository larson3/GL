#File: lab3.py
#Author: John Larson
#Date: 2/17/14
#Section: 2
#Email: larson3@umbc.edu
#Description: Lab 3, Cipher.  Encoding/Decoding a string.

def main():

    user_string = input("Please enter a string ")
    user_string = user_string.upper()

    for value in user_string:
        if value != " ":
            value = ord(value)
            value = value + 13
            if value > ord("Z"):
                value = value - 26
            value = chr(value)
            print(value)
            

main()
