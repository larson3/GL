 #Assign04 script

import glob
import os
import subprocess
import sys
import time
import datetime

def main():

	applist = glob.glob("app/*java")
	classlist = glob.glob("app/*class")
	originaltime = []
	newtime = []
	for currentapp in applist:
		originaltime.append(os.path.getmtime(currentapp))
	if classlist == []:
		subprocess.call(["javac","app/Assign01.java"])

	open('log.txt','w').close()
	count = 0
	while count < 10:
		print("----------Checking for any changes----------")
		count+=1
		newtime = []
		for currentapp in applist:
			newtime.append(os.path.getmtime(currentapp))
		if newtime != originaltime:
			print("Change detected.")
			reRun()
			originaltime = newtime
		else:
			with open("log.txt", "a") as theFile:
				theFile.write("Passed test\n")
		time.sleep(5)
	
	


def reRun():
		
	outfile = open('temp.txt','w')
	#logfile = open('log.txt','w')
	now = datetime.datetime.now()
	nowStr = str(now.strftime("%Y%M%d_%H%M%S"))
	print("Recompiling...")
	subprocess.call(["javac","app/Assign01.java"])
	newstring = "java"+" "+"app/Assign01"+" "+"-csv"
	subprocess.call("java"+" "+"app/Assign01"+" "+"-csv"+" "+"input/beFile.huge"+" "+"temp.txt",
                               stdout=outfile,shell=True)
	
	if(subprocess.call("diff -q -s -N "+"temp.txt"+" "+"expected/csvFile.huge",
                                     stdout=outfile,
                                     stderr=outfile,shell=True)) !=0:
	
	#this code works for creating a fail folder and storing the output
	#in a file within the fail folder
		print("Mismatch detected!")
		
		failPath = "/afs/umbc.edu/users/l/a/larson3/home/331/projects/Assign04/larson3/fail/"+nowStr
	#print(failPath)
		print("Making new folder...")
		os.makedirs(failPath)
		os.rename("temp.txt","fail/"+nowStr+"/fail.txt")
		#logfile.write("Failed test at: "+nowStr)
		with open("log.txt", "a") as theFile:
			theFile.write("Failed test at: "+nowStr+"\n")
		
	else:
		print("Same!")
		os.remove("temp.txt")
	
main()