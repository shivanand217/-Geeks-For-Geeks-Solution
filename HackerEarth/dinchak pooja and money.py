t = int(input())

while t > 0:
    ans = 0
    pi,ci = map(int,input().split())

    ans += pi*ci
    print(ans)

    t -= 1
