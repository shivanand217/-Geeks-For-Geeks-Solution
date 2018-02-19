t = int(input())
 
def check2(a, b, c):
    return a*a + b*b == c*c
 
def check(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return False
    if check2(a, b, c) or check2(a, c, b) or check2(b, c, a):
        if a + b > c and b + c > a and a + c > b:
            return True
    return False
 
for _ in range(t):
    a, b, c, x = map(int, input().split())
    if check(a+x, b+x, c) or check(a+x, b, c+x) or check(a, b+x, c+x):
        print("YES")
    else:
        print("NO")
