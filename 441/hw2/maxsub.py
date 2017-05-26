import math
import time

def bruteForce(subset,start,end):
	highestTotal = 0	

	for i in range(0,end):
		highestNow = 0
		for j in range(i,end):
			highestNow += subset[j]

			if highestNow > highestTotal:
				highestTotal = highestNow
				newstart = i
				newend = j
			
	
	return(newstart,newend,highestTotal)
	
	
def crossingMid(subset, start, mid, end):

    c = -999999
    sum = 0
    for i in range(mid, start - 1, -1):
        sum = sum + subset[i]
        if sum > c:
            c = sum
            maxLeft = i
    left = c
    c = -999999
    sum = 0

    for j in range(mid+1, end+1):
        sum = sum + subset[j]
        if sum > c:
            c = sum
            maxRight = j
    right = c

    return(maxLeft, maxRight, left + right)



def findMax(subset, start, end):

    if end == start:
        return start, end, subset[start]

    else:

        mid = math.floor((start+end)/2)
		#mid = floor(mid)

        leftstart, leftend, leftsum = findMax(subset, start, mid)
        rightstart, rightend, rightsum = findMax(subset, mid + 1, end)    
        crosslow, crossend, crosssum = crossingMid(subset, start, mid, end)         

        if leftsum >= rightsum and leftsum >= crosssum:
            return leftstart, leftend, leftsum
        elif rightsum >= leftsum and rightsum >= crosssum:
            return rightstart, rightend, rightsum
        else:
            return crosslow, crossend, crosssum
	
def findMaxMixed(subset,start,end):
	if end < 48:
		start,end,total = bruteForce(subset,0,end)
		return start,end,total
	else:
		start2,end2,total2 = findMax(subset, 0, end-1)
		return start2,end2,total2
	
def main():
	n=0
	flag = False
	set = [20, -21, 43, -23, -92, 45, -56, -5, 34, -17,
                    34, 65, 89, -109, 125, 2, -10, 89, 46, 65, -49, 
                    3, -45, 34, 76, 32, -76, -2, 3, -45, 44, 34, 67, 
                    -67, 99, -104, 11, -37, 44, 76, -90, 89, -32, 34, 
                    88, 56, -6, -89, -90, -34, -56, 23, 29, 2, 6, 9, 
                    2, -34, -45, 34, 22, -177, 44, 90, -45, -36, 55, 
                    23, 56, -56, -167, -54, 23, 45, 14, 62, -46, -56, 
                    -34, 45, 32, 20, -87, 39, 82, 95, -67, -45, 88, 
                    -36, 21, 18, 16, 81, -102, 99, -45, -67, -45, -76]
	while flag == False:
		n+=1
		beg = time.clock()
		for x in range(0,1000):
			start,end,total = bruteForce(set,0,n)
		stop = time.clock()
		#findMax(set,0,9)
		beg2 = time.clock()
		for x in range(0,1000):
			start2,end2,total2 = findMax(set, 0, n-1)
		stop2 = time.clock()
		
		beg3 = time.clock()
		for x in range(0,1000):
			start3,end3,total3 = findMaxMixed(set, 0, n)
		stop3 = time.clock()
		time1 = stop - beg
		time2 = stop2 - beg2
		time3 = stop3 - beg3
		print("n = ",n)
		print("BF - Start: ",start," End: ",end,"Total: ",total," Time: ",time1)
		print("RC - Start: ",start2," End: ",end2,"Total: ",total2," Time: ",time2)
		print("MX - Start: ",start3," End: ",end3,"Total: ",total3," Time: ",time3)
		
		#to test higher n, just change n, can go up to 99
		if n>50:
			flag = True
		
main()