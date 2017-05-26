def main():
    count = 0
    d = {}
    word = ""
    thelist = []
    newlist = []
    print("Testing")
    thefile = open("database.txt","r")
    for currentLine in thefile:
        currentLine = currentLine.strip()
       # currentLine.split(",")

        count+=1
        newlist = []
        
       # print(currentLine)
        for currentLetter in currentLine:
            if currentLetter != ",":          
                word = word+currentLetter
            
            else:
                newlist.append(word)
                word = ""
        newlist.append(word)
        word=""
        thelist.append(newlist)
   # print(thelist)
    count=0
    for currentLine in thelist:
        
        thename=""
        thename=thelist[count][0]+","+thelist[count][1]
        del thelist[count][0]
        del thelist[count][0]
        
        if thename not in d:
            d[thename]=thelist[count]
        else:
            d[thename].append(thelist[count])
        count+=1
    print(d)
main()
