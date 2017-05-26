def count(letter, myStr, theLen):
    if theLen == 0:
        return 0
    else:
        if myStr[0]==letter:
            return 1+count(letter, myStr[1:], theLen-1)
        else:
            return count(letter, myStr[1:], theLen-1)
        

def main():

    print("The count of letter a is: ", count("a", "adacdadaad", 10))
    print("The count of letter b is: ", count("b", "abacdadaad", 10))
    print("The count of letter c is: ", count("c", "abacdadaad", 10))
    print("The count of letter d is: ", count("d", "abacdadaad", 10))

main()
