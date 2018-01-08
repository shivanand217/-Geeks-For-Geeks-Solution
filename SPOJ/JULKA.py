import sys
for i in range(0,10):
	total = int(sys.stdin.readline())
	dif = int(sys.stdin.readline())
	k = (total+dif)/2
	p = (total-dif)/2
	print k
	print p
