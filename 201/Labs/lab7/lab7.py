def main():
    charLoop = False
    userFile = ""
    
    try:
        whichFile = input("Enter the file name: ")
        
        while charLoop == False:
            count = 0
            userFile = open(whichFile,"r")
            userChar = input("Enter a character: ")
            if len(userChar) == 1:
                for currentLine in userFile:
                    howMany = currentLine.count(userChar)
                    
                    print("Line # "+str(count) +" has " + str(howMany) + " of character "+userChar)
                    count += 1
                endLoop = input("Would you like to run it again? ")
                endLoop = endLoop.lower()
                if endLoop == "yes":
                    charLoop = False
                elif endLoop == "no":
                    charLoop = True
            userFile.close()
    except FileNotFoundError:
        print("invalid file")
main()
