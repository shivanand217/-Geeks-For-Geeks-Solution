import math

fact = []
mod = 1000000007

def solve():
    fact.append(1)
    for i in range(1,45010):
        p = fact[i-1]
        m = (p * i)%mod
        fact.append(m)
        
def find(p):
    ans = 0
    sq = int(math.sqrt(p))
    temp = 0
    for i in range(2,sq+1):
        if i*i <= p:
            if p%i == 0:
                k = int(p/i)
                if k == i:
                    ans += 1
                else:
                    ans += 2
    ans += 2
    return ans

t = int(input())
solve()

while t > 0:
    n = int(input())
    p = fact[n]    
    ans = find(p)
    print(ans)
    t -= 1
