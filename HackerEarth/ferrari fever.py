t = int(input())

while t > 0:
    n,x = map(int, input().split())
    arr = list(map(int, input().split()))
    s = sum(arr)
    if s%x == 0:
        print("Yes")
    else:
        print("No")
    
    t -= 1
