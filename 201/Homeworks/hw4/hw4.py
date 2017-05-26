#File: hw4.py
#Author: John Larson
#Date: 2/26/14
#Section: 2
#Email: larson3@umbc.edu

#Name: userOptions
#Desc: Present user with input options
#Input: None
#Output: Prints four options

def userOptions():

    print("Enter 1 to calculate the area of a circle")
    print("Enter 2 to calculate the surface are of a sphere")
    print("Enter 3 to calculate the volume of a sphere")
    print("Enter 4 to exit")

#Name: calcArea
#Desc: Will calculate the area of a circle
#Input: Radius
#Output: Area of a circle with given radius

def calcArea():
    #set up an end for the loop
    endFunction = 0
    while endFunction == 0:
        try:
            pi = 3.14159
            radius = float(input("Enter the radius: "))
            if radius < 0:
                print("The radius has to be positive")
            elif radius >= 0:
                #performs the equation
                circleArea = radius * radius * pi
                print("The area is: ", circleArea)
                endFunction = 1
        except ValueError:
            print("Radius must be a number")
            endFunction = 0
   
#Name: calcSurfaceArea
#Desc: Will calculate the surface area of a sphere
#Input: Radius
#Output: Surface area of sphere with a given radius

def calcSurfaceArea():
   
    endFunction = 0
    while endFunction == 0:
        try:
            pi = 3.14159
            radius = float(input("Enter the radius: "))
            if radius < 0:
                print("The radius has to be positive")
            elif radius >= 0:
                surfaceArea = 4 * pi * radius ** 2
                print("The surface area is: ", surfaceArea)
                endFunction = 1
        except ValueError:
            print("Radius must be a number")
            endFunction = 0

#Name: calcVolume
#Desc: Will calculare the volume of a sphere
#Input: Radius
#Output: Volume of a sphere with a given radius

def calcVolume():
    endFunction = 0
    while endFunction == 0:
        try:
            pi = 3.14159
            radius = float(input("Enter the radius: "))
            if radius < 0:
                print("The radius has to be positive")
            elif radius >= 0:
                volumeSphere = 4/3 * pi * radius ** 3
                print("The volume is: ", volumeSphere)
                endFunction = 1
        except ValueError:
            print("Radius must be a number")
            endFunction = 0

#Name: Main
#Desc: Will gather user input and run a range of mathematical operations
#Input: Int 1-4, then depending on choice any positive radius
#Output: Program will calculate area of a circle, surface area of a sphere and volume of a sphere

def main():

#Declaring variables
    userChoice1 = 1
    radius = 0
    pi = 3.14159
    circleArea = 0

#Show the user their options
    userOptions()

#Begin loop

    while userChoice1 != 4:

#Get user input
        try:
            userChoice1 = (input("Enter your choice: "))
            userChoice1 = int(userChoice1)
            if userChoice1 == 4:
                print("End of the program")
            elif userChoice1 == 1:
                #Calculate the radius
                calcArea()
            elif userChoice1 == 2:
                #Calculate the surface area
                calcSurfaceArea()
            elif userChoice1 == 3:
                #Calculate the volume
                calcVolume()

            elif userChoice1 > 4 or userChoice1 < 1:
                print("Choice should be in range of 1-4.")
        except ValueError:
            #Catching exception to the first user input
            try:
                userChoice1 = float(userChoice1)
                print("Number should be an int not a float")
            except ValueError:
                print("Choice needs to be a number")
            
        print("")
        userOptions()
main()
