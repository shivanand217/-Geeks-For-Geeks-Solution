def check(num):
    s = ""
    while num > 0:
        p = num%10
        k = str(p)
        s += k
        num = int(num/10)
    s = s[::-1]
    i = 1
    while i < len(s):
        if int(s[i]) < int(s[i-1]):
            return False
        i += 1
    return True

def solve(num):
    while num > 0:
        if check(num) == True:
            return num
        num -= 1

t = int(input())

while t > 0:    
    n = int(input())
    ans = solve(n)
    print(ans)
    t -= 1    
