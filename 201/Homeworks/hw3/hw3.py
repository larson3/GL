#File name: hw3.py
#Author: John Larsom
#Date: 2/22/2014
#Section: 2
#Email: larson3@umbc.edu
#Description: This program will generate a user submitted list and perform a range of functions based on user decisions.  This includes displaying a single sentence, displaying all sentences, replacing a sentence with a new one, switching two words from different sentences and counting every occurence of a single letter in the entire list.  Afterwards it will provide the user with a summary of their choices. 

def main():
    
#Declare variables

    sentences = 0
    usersentence1 = 0 
    usersentence2 = 0
    usersentence3 = 0
    usersentence4 = 0
    usersentence5 = 0
    usernum1 = 0
    usernum2 = 0
    usernum3 = 0
    userletter = 0
    replacement1 = 0
    swapword = 0
    replacement2 = 0
    insentence1 = 0
    insentence2 = 0
    count1 = 0
    count2 = 0
    count3 = 0
    count4 = 0
    count5 = 0
    invalidchoice = 0
    total = 0
#Displaying description of program
    print("This program will demonstrate lists")

#Get user input for how many sentences they would like to use
    sentences = int(input("How many sentences? "))

#Making a workaround if the user enters a negative number
    if sentences <= 0:
        sentences = 5

#Getting user input for the sentences in lower case and putting them in lists
    if sentences == 1:
        usersentence1 = str.lower( input("Enter a sentence: "))
        sentenceslist = list(usersentence1)
       
    elif sentences == 2:
        usersentence1 = str.lower(input("Enter a sentence: "))
        usersentence2 = str.lower(input("Enter a sentence: "))
        sentenceslist = list([usersentence1,usersentence2])
    
    elif sentences == 3:
        usersentence1 = str.lower(input("Enter a sentence: "))
        usersentence2 = str.lower(input("Enter a sentence: "))
        usersentence3 = str.lower(input("Enter a sentence: "))
        sentenceslist = list([usersentence1 , usersentence2 , usersentence3])

    elif sentences == 4:
        usersentence1 = str.lower(input("Enter a sentence: "))
        usersentence2 = str.lower(input("Enter a sentence: "))
        usersentence3 = str.lower(input("Enter a sentence: "))
        usersentence4 = str.lower(input("Enter a sentence: "))
        sentenceslist = list([usersentence1 , usersentence2 , usersentence3 ,usersentence4])
   
    else:
        usersentence1 = str.lower(input("Enter a sentence: "))
        usersentence2 = str.lower(input("Enter a sentence: "))
        usersentence3 = str.lower(input("Enter a sentence: "))
        usersentence4 = str.lower(input("Enter a sentence: "))
        usersentence5 = str.lower(input("Enter a sentence: "))
        sentenceslist = list([usersentence1 , usersentence2 , usersentence3 , usersentence4, usersentence5])

    print("-------------------")

#ask questions, repeat for every sentence input by the user
    for i in range(sentences):
        print("Enter 1 to see a sentence")
        print("Enter 2 to see the whole list")
        print("Enter 3 to change a sentence")
        print("Enter 4 to switch words")
        print("Enter 5 to count letters")
        usernum1 = int(input("Enter your choice: "))
#make decisions based on user input
#displaying user's selected sentence
        if usernum1 == 1:
            count1 += 1
            print("You selected choice 1")
            usernum2 = int(input("Which sentence? "))
            if usernum2 == 1:
                print(usersentence1)
            elif usernum2 == 2:
                print(usersentence2)
            elif usernum2 == 3:
                print(usersentence3)
            elif usernum2 == 4:
                print(usersentence4)
            elif usernum2 == 5:
                print(usersentence5)
            else:
                print("Invalid choice")
           
#Displaying all sentences       
        elif usernum1 == 2:
            count2 += 1
            print("You selected choice 2")
            for i in sentenceslist:
                print(i)
           
#Changing sentences
        elif usernum1 == 3:
            count3 += 1
            print("You selected choice 3")
            usernum3 = int(input("Which sentence? "))
            replacement1 = str.lower(input("Enter a new sentence: "))
            if usernum3 == 1:
                sentenceslist.remove(usersentence1)
                sentenceslist.insert(0,replacement1)
            elif usernum3 == 2:
                sentenceslist.remove(usersentence2)
                sentenceslist.insert(1,replacement1)
            elif usernum3 == 3:
                sentenceslist.remove(usersentence3)
                sentenceslist.insert(2,replacement1)
            elif usernum3 == 4:
                sentenceslist.remove(usersentence4)
                sentenceslist.insert(3,replacement1)
            elif usernum3 == 5:
                sentenceslist.remove(usersentence5)
                sentenceslist.insert(4,replacement1)
            else:
                print("Not a valid number")
           
#Swap a word from selected sentence with a word from another sentence
        elif usernum1 == 4:
            count4 += 1
            print("You selected choice 4")
            swapword = str.lower(input("Swap word: "))
            insentence1 = int(input("In sentence: "))
            replacement2 = str.lower(input("With word: "))
            insentence2 = int(input("In sentence "))
            if insentence1 >= 0 and insentence1 < sentences:
                if swapword in sentenceslist[insentence1]:
                    if insentence2 > 0 and insentence2 < sentences:
                        if replacement2 in sentenceslist[insentence2]:
                            if insentence1 != insentence2:
                                sentenceslist[insentence1] = sentenceslist[insentence1].replace(swapword,replacement2)
                                sentenceslist[insentence2] = sentenceslist[insentence2].replace(replacement2,swapword)
                            else:
                                print("Must be two different sentences")
                        else:
                            print("No word ", replacement2, "in sentence: ", sentenceslist[insentence2])
                    else:
                        print("No sentences with index ", insentence2)
                else:
                    print("No word ", swapword, "in sentence: ", sentenceslist[insentence1])
            else:
                print("No sentences with index ", insentence1)
                        
                                
#Counting all the instances of a user selected letter in the list
        elif usernum1 == 5:
            count5 += 1
            print("You selected choice 5")
            userletter = (input("Enter a letter: "))
            for i in sentenceslist:
                total += i.count(userletter)
            print("The count is ", total)
            
        else:
            invalidchoice += 1
            print("Invalid choice")

        print("--------------------")             
                    
   
#displaying count of user number selections
    print("Thank you for using this program")
    print("Choice 1 selected ", count1)
    print("Choice 2 selected ", count2)
    print("Choice 3 selected ", count3)
    print("Choice 4 selected ", count4)
    print("Choice 5 selected ", count5)
    print("Invalid choice selected ", invalidchoice)
main()
