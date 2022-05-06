 

# a global dictionary to store the production rules along with its corresponding non-terminal symbol
grammar = {}

def FormGrammar(str):                               
    x = str.split("->") # split the rules first with the leftmost nonterminal
    y = x[1]  # take the rules and then split it to receive the various rules 
    x.pop()
    z = y.split("|")
    x.append(z)
    grammar[x[0]]=x[1]

def removeDirectleftRecursion(grammarA, A):        
	temp = grammarA[A]
	tempCr = []
	tempInCr = []
	for i in temp:
		if i[0] == A:
			tempInCr.append(i[1:]+[A+"'"])
		else:
			tempCr.append(i+[A+"'"])
	tempInCr.append(["e"])
	grammarA[A] = tempCr
	grammarA[A+"'"] = tempInCr
	return grammarA
			
def checkForIndirect(grammarA, a, ai):
	if ai not in grammarA:
		return False 
	if a == ai:
		return True
	for i in grammarA[ai]:
		if i[0] == ai:
			return False
		if i[0] in grammarA:
			return checkForIndirect(grammarA, a, i[0])
	return False
			
	
def rep(grammarA, A):
	temp = grammarA[A]
	newTemp = []
	for i in temp:
		if checkForIndirect(grammarA, A, i[0]):
			t = []
			for k in grammarA[i[0]]:
				t=[]
				t+=k
				t+=i[1:]
				newTemp.append(t)

		else:
			newTemp.append(i)
	grammarA[A] = newTemp
	return grammarA




def rem(grammar):
	c = 1
	conv = {}
	grammarA = {}
	revconv = {}
	for j in grammar:
		conv[j] = "A"+str(c)
		grammarA["A"+str(c)] = []
		c+=1

	for i in grammar:
		for j in grammar[i]:
			temp = []	
			for k in j:
				if k in conv:
					temp.append(conv[k])
				else:
					temp.append(k)
			grammarA[conv[i]].append(temp)


	
	for i in range(c-1,0,-1):
		ai = "A"+str(i)
		for j in range(0,i):
			aj = grammarA[ai][0][0]
			if ai!=aj :
				if aj in grammarA and checkForIndirect(grammarA,ai,aj):
					grammarA = rep(grammarA, ai)

	for i in range(1,c):
		ai = "A"+str(i)
		for j in grammarA[ai]:
			if ai==j[0]:
				grammarA = removeDirectleftRecursion(grammarA, ai)
				break

	op = {}
	for i in grammarA:
		a = str(i)
		for j in conv:
			a = a.replace(conv[j],j)
		revconv[i] = a

	for i in grammarA:
		l = []
		for j in grammarA[i]:
			k = []
			for m in j:
				if m in revconv:
					k.append(m.replace(m,revconv[m]))
				else:
					k.append(m)
			l.append(k)
		op[revconv[i]] = l

	return op

n = int(input("Enter number  of production rules: "))
for i in range(n):
    # The input format is A->alpha|beta|.. so on separated by a '|' symbol
    grammar=input()
    FormGrammar(grammar)
   
result = rem(grammar)

for x,y in result.items():
    print(f'{x} -> {y}')
