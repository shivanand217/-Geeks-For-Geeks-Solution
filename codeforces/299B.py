
a = []
n,m,d = [int(x) for x in input().split()]

lenn = n*m
rem = 0
prev = -1
flag = 1

for i in range(1,n+1):
    p = [int(k) for k in input().split()]
    for j in range(len(p)):
        a.append(p[j])
        rem = p[j] % d
        if prev == -1:
            prev = rem
        else:
            if prev != rem:
                flag=0
    
if flag == 0:
    print("-1")
else:
    if n==1 and m==1:
        print("0")
    else:
        a = sorted(a)
        ans1 = 0
        ans2 = 0
        if (lenn&1) == 1:
            indx = lenn/2
            for i in range(len(a)):
                if i != indx:
                    ans1 += int(abs(a[i] - a[indx])/d)
            print(ans1)
        else:
            indx1 = int(lenn/2)
            indx2 = int(lenn/2)-1
            for i in range(len(a)):
                if i != indx1:
                    ans1 += int(abs(a[i] - a[indx1])/d)
            for i in range(len(a)):
                if i != indx2:
                    ans2 += int(abs(a[i] - a[indx2])/d)
            ans = min(ans1,ans2)
            print(ans)
            
                
            
    
    
