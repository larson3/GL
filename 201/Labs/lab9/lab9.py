def draw(theChar,theNum):
    
    if theNum >0:
        print(theChar*theNum)
        draw(theChar,theNum-1)
        print(theChar*theNum)
    else:
        return

def secondDrawing(theChar,theNum,whiteSpace):


    if theNum >0:
        print(theChar*theNum+ " "*whiteSpace*2+ theChar*theNum)
        secondDrawing(theChar,theNum-1,whiteSpace+1)
        print(theChar*theNum+ " "*whiteSpace*2+ theChar*theNum)
    else:
        return

def main():
    whiteSpace = 0
    theChar = input("Enter char: ")
    theNum = int(input("How many: "))
    print("Here is the original drawing")
    draw(theChar,theNum)
    print("Here is the second drawing")
    secondDrawing(theChar,theNum,whiteSpace)

main()
