import sys
from collections import defaultdict
def main():
	whichFile = sys.argv[1]
	theDict = defaultdict(int)
	try:
		theDatabase = open(whichFile, "r")
	except FileNotFoundError:
		print("Invalid input, exiting program") 
		sys.exit()
	for currentLine in theDatabase:
		currentLine.strip()
		for word in currentLine.split():
			theDict[word]+=1
	sortedDict = sorted(theDict.items(), key = lambda t:t[1])

	for current in sortedDict:
		print(current[1],current[0])

main()