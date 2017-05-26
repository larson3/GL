def main():
    errorCheck = 1
    while errorCheck == 1:
        try:
            
            pinNum = int(input("Please enter a pin number: "))
            if pinNum >= 99999:
                print("Not a string of 5 or less digits")
            elif pinNum <= 0:
                print("Not a string of 5 or less digits")
            else:
                print("Pin number created!")
                errorCheck = 0
        except ValueError:
            print("Not a string of 5 or less digits")

main()

    
