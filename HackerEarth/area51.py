import math as m
t = int(input())

while t > 0:
    n,x = (map(int, input().split()))

    if x < n:
        print("0")
    else:
        ans = m.factorial(n)
        p = ans/x
        q = ans - p*x
        print(q)
        
    t -= 1
