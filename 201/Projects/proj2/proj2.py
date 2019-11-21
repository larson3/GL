#file: proj2.py
#author: John Larson
#Date: 5/3/2014
#Section: 1
#Email: larson3@umbc.edu
#Description:
#This file contains code which will display a bookstore's inventory by title, author and allow changes to be made to the inventory

#greeting() prints a greeting for the user
#input: none
#output: greeting

def greeting():
    print("Welcome to the bookstore program!")
    this will fail

def properName(wholeName):
    letterList=[]
    fixedName=""
    while true:
        print("Poop")
    lowerName=wholeName.lower()
    #changing all to lower, then two letters to caps
    for letter in lowerName:
        letterList.append(letter)
    #changing first letter
    letterList[0]=letterList[0].upper()
    commaIndex=letterList.index(",")
    #changing first letter after comma
    letterList[commaIndex+1]=letterList[commaIndex+1].upper()
    for letter in letterList:
        fixedName+=letter
    return fixedName

#properTitle() will change a user entered title to captials in from of words
#input: title
#output: book title with proper capitals
def properTitle(title):
    count=0
    correctTitle=""
    title=title.lower()
    #splitting into a list
    titleList=title.split()
    #loop through values in list
    for word in titleList:
        newWord=""
        letterList=[]
        for letter in word:
            letterList.append(letter)
        #changing the first letters of the words to caps
        letterList[0]=letterList[0].upper()
        for letter in letterList:
            newWord+=letter
        #adding new words together
        correctTitle+=newWord
        #adding spaces
        if count<len(titleList)-1:
            correctTitle+=" "
            count+=1
    return correctTitle


#readDatabase() will check for a file, then turn the contents of said file into a dictionary of 2D lists
#input: theInventory
#output: dictionary
def readDatabase(theInventory):
    count = 0
    word = ""
    thelist = []
    newlist = []
    flag = True
    #setting up a loop to error check an incorrect entry
    while flag:
        whichFile = input("Enter the name of the file: ")
        try:
            #saving file content to a variable
            theDatabase = open(whichFile, "r")
            flag = False
        except FileNotFoundError:
            print("Error reading database")    
   
    for currentLine in theDatabase:
        #Getting rid of \n
        currentLine = currentLine.strip()
        count+=1
        newlist = []
       
        for currentLetter in currentLine:
            #creating my own .split() function because I am dumb
            if currentLetter != ",":
                word = word+currentLetter

            else:
                #adding the words separated by a comma to  a list
                newlist.append(word)
                word = ""
        newlist.append(word)
        word=""
        thelist.append(newlist)
   
    count=0
    for currentLine in thelist:

        thename=""
        #creating an author's name
        thename=thelist[count][0]+","+thelist[count][1]
        #deleting author's name from list
        del thelist[count][0]
        del thelist[count][0]
        #Creating a dictionary key for new authors
        if thename not in theInventory:
            theInventory[thename]=[]
            theInventory[thename].append(thelist[count])
        #adding to the dictionary of existing authors
        else:
            theInventory[thename].append(thelist[count])
        count+=1

#printMenu() will display the menu for the user
#input: none
#output: printed menu
def printMenu():
    flag = True
    #printing the menu
    print("\n--------------------------------")
    print("Enter 1 to display the inventory")
    print("Enter 2 to display the books by one author") 
    print("Enter 3 to add a book") 
    print("Enter 4 to change the price") 
    print("Enter 5 to change the qty on hand") 
    print("Enter 6 to view the total number of books in the inventory")
    print("Enter 7 to see the total amount of the entire inventory")
    print("Enter 8 to exit")
    while flag:
        #making sure entry is valid
        try:
            choice = input("Enter your choice: ")
            if int(choice) >0 and int(choice) <9:
                return choice
        except ValueError:
            flag = True

#alphabetizeIt() will make a list of Authors' names in alphabetical order
#input: theInventory
#output: sorted list
def alphabetizeIt(theInventory):
    tempList=[]
    swap=True
    #making a new list of authors
    for author in theInventory:
        tempList.append(author)
    while swap==True:
        swap=False
        for i in range(len(tempList)-1):
            #bubble sorting authors based on first letter's ASCII value
            if ord(tempList[i][0])>ord(tempList[i+1][0]):
                temp=tempList[i]
                tempList[i]=tempList[i+1]
                tempList[i+1]=temp
                swap=True
    return tempList

#alphabetizeTitles() will make a list of book names in alphabetical order
#input: theInventory
#output: sorted list
def alphabetizeTitles(currentAuthor,theInventory):
    tempList=[]
    swap=True
    #the same sort function with minor changes
    for currentBook in theInventory[currentAuthor]:
        #this time we make a list of the books' info
        tempList.append(currentBook)
    while swap==True:
        swap=False
        for i in range(len(tempList)-1):
            #going into my 2D list and checking first letter's ASCII value
            if ord(tempList[i][0][0])>ord(tempList[i+1][0][0]):
                temp=tempList[i]
                tempList[i]=tempList[i+1]
                tempList[i+1]=temp
                swap=True
    return tempList

#displayInventory() will show every book in the inventory in Alphabetical order of Authors and Titles
#input: theInventory
#output: prints sorted inventory
def displayInventory(theInventory):
   
    alphaList=alphabetizeIt(theInventory)
    for currentAuthor in alphaList:
        count=0
        #looping through author's names
        print("The author is "+currentAuthor)
        print(" ")
        for marker in theInventory[currentAuthor]:
            #going into the dictionary and sorting book titles
            tempList=[]
            tempList=alphabetizeTitles(currentAuthor,theInventory)
            #printing results with a count to track which book we are on
            print("        The title is: "+tempList[count][0])
            print("        The qty is: "+tempList[count][1])
            print("        The price is: "+tempList[count][2])
            print(" ")
            print("        ----")
            print(" ")
            count+=1

#displayAuthorsWork() will ask for user input then display all works by that author in inventory
#input: theInventory
#output: sorted works by author
def displayAuthorsWork(theInventory):
    lowerList=[]
    tempList=[]
    firstName=input("Enter the author's first name: ")
    lastName=input("Enter the author's last name: ")
    wholeName=lastName+","+firstName
    #loop through authors names and put in lower cases
    for author in theInventory:
        lowerName=author.lower()
        lowerList.append(lowerName)
    if wholeName.lower() in lowerList:
        #loop through
        print(" ")
        for currentAuthor in theInventory:
            #printing results
            if wholeName.lower()==currentAuthor.lower():
                tempList=alphabetizeTitles(currentAuthor,theInventory)
                for i in range(len(tempList)):
                    print("        The title is: "+tempList[i][0])
                    print("        The qty is: "+tempList[i][1])
                    print("        The price is: "+tempList[i][2])
                    print(" ")
                    print("        ----")
                    print(" ")
    else:
        #put name in correct caps
        fixedName=properName(wholeName)
        
        print("Sorry but no books by "+fixedName+" in the inventory")
                
#addBook() will take in a new author, title, quantity and price and add them to the dictionary
#input: theInventory
#output: new entry to the inventory
def addBook(theInventory):
    bookCheck=True
    count=0
    flag=True
    bookList=[]
    #gathering info
    firstName=input("Enter the author's first name: ")
    lastName=input("Enter the author's last name: ")
    theName=lastName+","+firstName
    #fixing caps in names
    theName=properName(theName)
    title=input("Enter the title: ")
    title=properTitle(title)
    bookList.append(title)
    if theName in theInventory:
        for currentTitle in theInventory[theName]:
            if title in currentTitle:
                bookCheck=False
                print("This book is already in the inventory and cannot be added again")
    #loop until correct entry
    if bookCheck==True:
        while flag:
            try:
                quantity=int(input("Enter the Quantity: "))
                #checking to make sure positive
                if quantity >0:
                    flag=False
                    quantity=str(quantity)
                    #adding to a new list
                    bookList.append(quantity)

                else:
                    print("Invalid input for qty.")
            
            #exception for non-int
            except ValueError:
                flag=True
                print("Invalid input for qty")

        flag=True
        while flag:
            try:
                price=str(input("Enter the Price: "))
                #checking to make sure all numbers and a float to the hundredth
                if float(price) >0 and price[-3]==".":
                    flag=False
                else:
                    print("Invalid input for price.")
            #exceptions for possible errors such as non-int, too short etc
            except TypeError:
                flag=True
                print("Invalid input for price")

            except IndexError:
                flag=True
                print("Invalid input for price")

            except ValueError:
                flag=True
                print("Invalid input for price")
        #adding to list
        bookList.append(price)

        #creating dictionary entry
        if theName in theInventory:
            theInventory[theName].append(bookList)
        else:
            theInventory[theName]=[]
            theInventory[theName].append(bookList)

#changePrice() will take a user entry and change the price of a chosen author's title
#input: the inventory
#output: changed price for a title
def changePrice(theInventory):
    titleCount=0
    flag=True
    firstName=input("Enter the author's first name: ")
    lastName=input("Enter the author's last name: ")
    wholeName=lastName+","+firstName
    #putting name in proper caps
    wholeName=properName(wholeName)
    #proceeding if name in the dictionary
    if wholeName in theInventory:
        title=input("Enter the title: ")
        title=properTitle(title)
        #looping through books by author
        for i in range(len(theInventory[wholeName])):
            if title in theInventory[wholeName][i]:
                #looping until we get a correct price
                while flag:
                    try:
                    
                        price=str(input("Enter the Price: "))
                        #checking to make sure all numbers and a float to the hundredth
                        if float(price) >0 and price[-3]==".":
                            flag=False
                            #saving old price for printing
                            oldPrice=theInventory[wholeName][i][2]
                            theInventory[wholeName][i][2]=price
                            print("The price will be updated from "+oldPrice+" to "+price)
                            
                        else:
                            print("Invalid input for price.")
                    #exceptions for float making errors
                    except TypeError:
                        flag=True
                        print("Invalid input for price")
                    except IndexError:
                        flag=True
                        print("Invalid input for price")
                    
                    except ValueError:
                        flag=True
                        print("Invalid input for price")             
            else:
                titleCount+=1
        #if every loop has not found a match we print this
        if titleCount>=len(theInventory[wholeName]):
            print("No book with the title "+title+" by "+wholeName+" in inventory")
    #if the author does not show up in the dictionary
    else:
        print("No such author in your database.  So you cannot change the price")

#changeQty() will change the quantity of a user selected title
#input: the inventory
#output: changed quantity
def changeQty(theInventory):
    titleCount=0
    flag=True
    firstName=input("Enter the author's first name: ")
    lastName=input("Enter the author's last name: ")
    wholeName=lastName+","+firstName
    #putting name in proper caps
    wholeName=properName(wholeName)
    #proceeding if name in the dictionary
    if wholeName in theInventory:
        title=input("Enter the title: ")
        title=properTitle(title)
        #looping through books by author
        for i in range(len(theInventory[wholeName])):
            if title in theInventory[wholeName][i]:
                #looping until we get a correct quantity
                while flag:
                    try:

                        quantity=str(input("Enter the Qty: "))
                        #checking to make sure all numbers and a float to the hundredth
                        if int(quantity) >0:
                            flag=False
                            #saving old quantity for printing
                            oldQuantity=theInventory[wholeName][i][1]
                            theInventory[wholeName][i][1]=quantity
                            print("The quantity will be updated from "+oldQuantity+" to "+quantity)

                        else:
                            print("Invalid input for quantity.")
                    
                    except ValueError:
                        flag=True
                        print("Invalid input for quantity")
            else:
                titleCount+=1
        #if every loop has not found a match we print this
        if titleCount>=len(theInventory[wholeName]):
            print("No book with the title "+title+" by "+wholeName+" in inventory")
    #if the author does not show up in the dictionary
    else:
        print("No such author in your database.  So you cannot change the quantity")


#totalQty() will add together the total amount of books in the inventory
#input: theInventory
#output: total quantity of books
def totalQty(theInventory):
    totalBooks=0
    for currentAuthor in theInventory:
        for currentBook in theInventory[currentAuthor]:
            #adding an integer version of the index 1 to a variable
            howMany=int(currentBook[1])
            #adding it all together
            totalBooks+=howMany
    totalBooks=str(totalBooks)
    print("The total number of books is "+totalBooks)

#calculateTotalAmount() will take the total value of each title and add them together
#input: theInventory
#output: total value of inventory
def calculateTotalAmount(theInventory):
    valueBooks=0
    for currentAuthor in theInventory:
        for currentBook in theInventory[currentAuthor]:
            #adding an integer version of the index 1 to a variable
            howMany=int(currentBook[1])
            #making sure its a float, then assigning index to to a variable
            price=float(currentBook[2])
            #multiply them together to get the value of a single title
            value=howMany*price
            valueBooks+=value
    #valueBooks=str(valueBooks)
    print("The total value of the inventory is $"+"%.2f" %valueBooks)

def main(): 
 
    #print greeting 
    greeting() 
 
    #dictionary to hold the inventory 
    theInventory ={} 
 
    #put the data in the file into the dictionary 
    readDatabase(theInventory) 
 
    flag = True 
 
    #keep looping till flag is set to False 
    while flag: 
 
        choice = printMenu() 
        if choice=="1": 
            displayInventory(theInventory) 
        elif choice=="2": 
            displayAuthorsWork(theInventory) 
        elif choice=="3": 
            addBook(theInventory) 
        elif choice=="4": 
            changePrice(theInventory) 
        elif choice=="5": 
            changeQty(theInventory) 
        elif choice=="6": 
            totalQty(theInventory) 
        elif choice=="7": 
            calculateTotalAmount(theInventory) 
        elif choice=="8": 
            print ("Thank you for using this program") 
            flag = False 
        else: 
            print ("Invalid choice") 
 
 
main() 
