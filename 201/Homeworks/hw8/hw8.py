#File: hw8.py
#Author: John Larson
#Date: 3/31/14
#Section: 2
#Email: larson3@umbc.edu
#Description: This file contains code which will import a text file, and then play a two player text based game with the user.

#whichFile() will ask for the user to enter the name of a file, it will then attempt to open the file, reprompting the user if the file does not exist
#Input: none
#Output: the file name

def whichFile():
    loopCheck = False
    while loopCheck == False:
        #asking for user input
        inputFile = input("Enter the name of your word file: ")
        try:
            #opening the selected file
            userFile = open(inputFile, "r")
            loopCheck = True
        #exception for if the user forgets the name of their own file
        except FileNotFoundError:
            print("No such file")
    return userFile

#switchToList() will take the user selected file and put it into a list so it can be easily accessed
#Input: user file name
#Output: the file in list form

def switchToList(userFile):
    gameList = []
    #placing the contents of the imported file into a list
    for currentLine in userFile:
        #getting rid of the \n
        currentLine = currentLine.strip()
        currentLine = currentLine.upper()
        gameList.append(currentLine)
    return gameList

#roundFunction() will take the gameList and loop through the items on the list.  It will begin a game, and will not break the loop until all of the letters in the word have been guessed
#Onput: the current word in the list, the list itself, the round count, and the turn count
#Output: The player whose turn it is

def roundFunction(currentLine,scoreList,count,turnCount):
    correctLetters = []
    #begin looping the round until the word has been guessed
    print("Round ",count)
    while len(correctLetters) != len(currentLine):
        #turnCount switches between player1 and player2      
        if turnCount % 2 == 0:
            whichPlayer = 1
        else: 
            whichPlayer = 2
        #calling turnFunction, which will return how many correct guesses the players have thus far
        turnFunction(currentLine,correctLetters,whichPlayer,scoreList)
        #adding 1 to alternate between players
        if len(correctLetters) != len(currentLine):
            turnCount += 1
    return whichPlayer

#turnFunction() will allow one player to continue guessing until they either guess incorrectly, repeat a guess, or guess all the letters
#Input: The current word, the correct letters, whose turn it is, the current score
#Output: none

def turnFunction(currentLine, correctLetters, whichPlayer,scoreList):
    turnLoop = True
    guessLetter= ""
    while turnLoop == True:
        #calling the display function which will show the word with _'s and count how many correct entries there are
        displayCorrectFunction(currentLine,correctLetters,whichPlayer,guessLetter)
        if whichPlayer == 1:
            #save a score to player 1
            scoreList[0] += calcScoreFunction(currentLine,guessLetter,correctLetters)
        else:
            #save a score to player 2
            scoreList[1] += calcScoreFunction(currentLine,guessLetter,correctLetters)
        
        #ending the round if the word has been guessed
        if len(correctLetters) == len(currentLine):
            return
        #displaying the current score
        printScoreFunction(whichPlayer, scoreList)

        #taking in a new guess and running through the loop again
        guessLetter = guessLoopFunction(correctLetters,currentLine,scoreList,whichPlayer)
        
        #ending the loop if the player guesses incorrectly
        if guessLetter == "":
            turnLoop == False
            return
        
#guessLoopFunction() will ask the user to enter a letter, it will check to see if the letter is in the word.
#Input: correct letters, current word, current score, whose turn it is
#Output: either will return the guessed letter or an empty string

def guessLoopFunction(correctLetters,currentLine,scoreList,whichPlayer):
    guessLoop = True
    #begin guess loop
    while guessLoop == True:
        guessLetter = input("Enter a letter: ")
        #make it not case sensitive
        guessLetter = guessLetter.upper()
        #in case they guess a number or symbol
        if len(guessLetter)==1 and ord(guessLetter) in range(65,91):
            guessLoop = False
    #if guessLetter is not in the word, we send back a return of ""
    if guessLetter not in currentLine:
        print("No letter "+guessLetter+" in the word.")
        return ""
    #if the user selects an already chosen word, then they lose their turn and a point
    elif guessLetter in correctLetters:
        print("The letter "+guessLetter+"  has already been selected")
        #calling the function to take away points
        subtractPointsFunction(scoreList,whichPlayer)
        return ""
    #otherwise their selected letter gets returned
    else:
        return guessLetter

#subtractPointsFunction() will take away points if the user somehow manages to guess the same letter twice or more
#Input: score list and whose turn
#Output: minus 1 to the player's score

def subtractPointsFunction(scoreList,whichPlayer):
    #only wrote this as a function because I was out of lines
    if whichPlayer == 1:
        scoreList[0] -= 1
    else:
        scoreList[1] -= 1

#displayCorrectFunction() will begin by displaying underscores for every letter in the word.  It will then update and display correctly guessed letters in the appropriate spot.
#Input: the current word, correct letters, whose turn and the guessed letter
#Output: progress made on guessing the word

def displayCorrectFunction(currentLine,correctLetters,whichPlayer,guessLetter):
    #leaves the function if the user re-enters a letter
    if guessLetter in correctLetters:
        return
    #start looping through each individual letter
    for currentLetter in currentLine:
        #if the current letter = the guessed letter we print and list it
        if currentLetter == guessLetter:
            print(guessLetter, end="")        
            correctLetters.append(guessLetter)
        #taking values from the correct letter list and plugging them in
        elif currentLetter in correctLetters:
            print(currentLetter, end="")
        #printing "_" for any unguessed values
        else:
            print("_ ", end="")
    #printing a blank line to reduce cluttered appearance
    print("\n")
    return

#calcScoreFunction() will add points for any correctly guessed letters
#Input: current word, guessed letter, correctly guessed letters
#Output: updated score total

def calcScoreFunction(currentLine,guessLetter,correctLetters):
    playerScore = 0
    #this will add a point per occurence if the letter is in the word
    for currentLetter in currentLine:
        if guessLetter == currentLetter:
            playerScore += 1
    return playerScore
            
#whoWonFunction() will compare point totals and declare a winner
#Input: final scores
#Output: prints the winners

def whoWonFunction(scoreList):
    #comparing final totals after the function runs its course
    if scoreList[0] > scoreList[1]:
        print("Player 1 wins!")
    elif scoreList[0] < scoreList[1]:
        print("Player 2 wins!")
    else:
        print("The game was a draw")

#printScoreFunction() will print the running total before user input
#Input: which player and scores
#Output: the running total

def printScoreFunction(whichPlayer,scoreList):
    #prints out the running total before every user input
    print("Player "+str(whichPlayer)+"'s turn")
    print("----------------")
    print("The Score for Player 1 is: "+str(scoreList[0]))
    print("The Score for Player 2 is: "+str(scoreList[1]))
    print("----------------")
    return

def main():
    gameList = []
    scoreList = [0,0]
    count = 1
    turnCount = 2
    #open the file
    userFile = whichFile()
    #make a list out of the file
    gameList = switchToList(userFile)
    #begin game loop
    for currentLine in gameList:
        roundFunction(currentLine,scoreList,count,turnCount)
        #turnCount -=1
        #keeping track of rounds
        count+=1
    #displaying the winner at the end of the game
    whoWonFunction(scoreList)
    
    
main()

     
