#Student: John Larson
#CMSC 441 -- Project 2
#
# This code will generate two safe prime numbers of user-decided size
# the size can be changed by simply altering the size variable at the 
# top of main, the size in bits.  To input custom values for p and q-1
# see the description at the top of main.  This code is intended for
# use with python 3. 

import random
import time


#creating a class for this because python doesn't let me make structs
class ModInverse:
	def __init__(self, e, phi):
		self.y=phi
		self.x=e
		q=0
		r=0

#witness is the part of the miller-rabin test which tests primality		
def witness(a,n):
	t = 0
	x = []

	u = n - 1
	#shaving off zeroes from the binary representation until we get to
	#an odd number
	while u % 2 == 0:
		t+=1
		u =  u // 2
	
	#this is a faster modular exponentiation, think of it like a ** u % n
	x.append(pow(a,u,n))
	#running the main logic of the two test cases
	for i in range(1,t+1):
		x.append(x[i-1] ** 2 % n)
		if x[i] == 1 and x[i-1] != 1 and x[i-1] != n-1:
			return True
	if x[t] != 1:
		return True
	return False
	
#this just runs the test 20 times with different a's to make the chances
#of an error ~0
def millerRabin(n):
	for j in range (1,20):
		a=random.randint(1,n-1)
		if witness(a,n):
			return False
	return True

#this is an extended euclidean algorithm which will return a modular inverse
def extEuclid(a,b):
	#s holds the important values from the regular euclidean algorithm
	s=[]
	#p then uses those values to reverse engineer an inverse
	p=[]
	i=0
	x=2
	phi = b
	#initializing the first entry in s with the parameters brought into
	#the function
	newS = ModInverse(a,b)
	newS.q = newS.y // newS.x
	newS.r = newS.y % newS.x
	s.append(newS)
	i+=1
	#print("y: ",newS.y," x: ",newS.x," q: ",newS.q," r: ",newS.r)
	#this while loop populates s, we know we're done when we have 0 remainder
	while newS.r !=0:
		newS = ModInverse(s[i-1].r,s[i-1].x)
		newS.q = newS.y // newS.x
		newS.r = newS.y % newS.x
		s.append(newS)
		i+=1
	#	print("y: ",newS.y," x: ",newS.x," q: ",newS.q," r: ",newS.r)
	p.append(0)
	p.append(1)
	GCD = s[i-1].x
	#print("GCD: ", GCD)
	#if GCD isn't 1, the numbers aren't coprime and cannot be inverted
	if GCD == 1:
		while x!=i+1:
			newP = (p[x-2] - p[x-1] * s[x-2].q)%phi
			p.append(newP)
			x+=1
		inverse = p[i]
		return inverse
	else:
		print("GCD not 1, cannot invert")
	
	
def gcd(a, b):

    while b:
        a, b = b, a%b
    return a


def main():
	#below input the desired size of the modulus
	size = 40
	# if you want to test a specific p and q, change their values here and
	# turn pqFlag to True.  They will NOT be tested unless for primality
	# they are generated in the program! 
	pqFlag = False
	p = 0
	q = 0
	
	m = 1
	flag = True
	inverse = 0
	#we are subtracting one below to ensure that our safePrime will be 
	#within the input size
	size -=1
	#loop twice to get two numbers
	if not pqFlag:
		for z in range (2):
			n=random.getrandbits(size//2)

			while n == 0 or n==1:
				n=random.getrandbits(size//2)
				#safePrime = n*2+1
			#safe primes are of this form
			safePrime = n*2+1
			#but they BOTH need to be prime
			while not millerRabin(n) or not millerRabin(safePrime):
			#while not millerRabin(n):
				n=random.getrandbits(size//2)
				safePrime = n*2+1
				while n == 0 or n==1:
					n=random.getrandbits(size//2)
					safePrime = n*2+1
			#print(n,",",safePrime)
			#gotta save em in different places
			if z == 0:
		
				p = safePrime
				#p = n
			else:
				q = safePrime
				#q = n
	modulus = p*q
	print("modulus:", modulus,"p: ",p," q: ",q)
	phi = (p-1)*(q-1)
	#this loop will generate e's until e is coprime with phi
	while flag:
		e = random.randint(1,phi-1)
	
		#now to ensure that e is odd
		while e % 2 != 1:
			e = random.randint(1,phi-1)	
		#print("Phi: ",phi,"e:",e)
	
		inverse = extEuclid(e,phi)
		#if there was no possible inverse the function returns null
		if inverse != None:
			flag = False
			
	print("Public Key: ",e," , ",modulus)
	print("Private Key: ",inverse," , ",modulus)
	
	message = "I deserve an A"
	#print("I deserve an ...")
	x = 0

	for c in message:
		x = x << 8
		x = x ^ ord(c)
		print("Original: ",x)
		x = pow(x,e,modulus)
		#x = (x ** e) % modulus
	print("Original: ",x)
	x = pow(x,e,modulus)
	print("Encrypted: ",x)
	x = pow(x,inverse,modulus)

	#print("Decrypted: ",x)
	print("Modulus:   ",modulus)

		
	#modulus == n , e == e , inverse == d 
	
main()
