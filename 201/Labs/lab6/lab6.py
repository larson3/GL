def errorCheck(password):
    retVal = False
    hasNum = False
    if "!" in password:
        print("Error: No !'s")
        retVal = True
    if "?" in password:
        print("Error: No ?'s")
        retVal = True
    if "." in password:
        print("Error: No .'s")
        retVal = True
    length = len(password)
    if length <= 4:
        print("Error: less than 5 characters.")
        retVal = True
            
    for i in password:
        if ord(i)>= 48 and ord(i)<=57:
             hasNum = True
            
    if hasNum == False:
        print("Password needs a number")
        retVal = True

    if retVal == True:
        return True


def main():
    userPass = input("Please enter a password: ")
    while (errorCheck(userPass)):
        userPass = input("Please enter a password: ")
    
    print("Password created!")

main()
        

