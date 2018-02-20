t = int(input())

mod = 1000000007

while t > 0:
    n = int(input())
    res = (n)*(n + 1)*(3*n*n + 7*n + 2)
    res /= 24
    res %= mod
    res = int(res)
    print(res)
    t-=1
    
