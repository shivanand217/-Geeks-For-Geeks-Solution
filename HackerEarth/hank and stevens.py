t = int(input())

while t > 0:
    n = int(input())
    
    arr = list(map(int, input().split()))
    p,q = map(int, input().split())

    p-=1
    q-=1
    ans = abs(arr[p]-arr[q])
    
    print(ans)

    t-=1
