n = input().split(' ')
j = 0
for i in n:
    if j == 0:
        j+=1
        continue
    number = int(i)
    denom = 1<<number
    numer = 1
    print("%d %d" %(numer, denom), end=" ")


