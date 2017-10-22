#!/usr/bin/python
C = [[1,2,3,4], [3,4], [2], [4,5,6], [4,5], [7]]
C.sort(reverse=True)
S=set()
R=[]
for i in C:
	flag=0
	for j in i:
		if j not in S:
			flag=1
        	break
	if flag==1:
		R.append(i)
		for k in i:
			S.add(k)
for j in R:
    print j