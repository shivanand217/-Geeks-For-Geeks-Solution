n = int(input())
fl = 1

a = [int(x) for x in input().split()]

for i in range(1,n+1):
    if a[i] > 1 and a[i-1] > 1:
        fl = 0
        break

if fl == 1:
    print("perfect")
else :
    print("ambiguous")
    print("0", end=" ")
    cnt=1
    x=1
    fl=1
    for i in range(1,n+1):
        for j in range(a[i]):
            print(cnt,end=" ")
            x += 1
        cnt=x
    print()
    print("0", end=" ")
    cnt=1
    x=1
    fl=1
    for i in range(1,n+1):
        if a[i] > 1 and a[i-1] > 1 and fl == 1:
            fl = 0
            for j in range(a[i]-1):
                print(cnt, end=" ")
                x += 1
            print(cnt-1,end=" ")
            x += 1
        else:
            for j in range(a[i]):
                print(cnt,end=" ")
                x += 1
        cnt=x
                
        
