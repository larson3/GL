def main():
    
    list1 = [1,2,3,4,5,6]
    loopEnd = len(list1)
    while loopEnd != 0:
        print("This is number 1: ", list1[0], "This is number 2: ", list1[1])
        del list1[:1]
        loopEnd -= 2
main()
