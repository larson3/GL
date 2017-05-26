def main():
    newlist=[]
    sortlist=[]
    myList=("a","q","d","r","t","h","c","d","i")
    print(myList)
    for i in range(len(myList)):
        i=ord(myList[i])
        print(i)
        newlist.append(i)
    newlist.sort()
    print(myList)
    print(newlist)
    for letter in newlist:
        newletter=chr(letter)
        sortlist.append(newletter)
    print(sortlist)
    
main()
