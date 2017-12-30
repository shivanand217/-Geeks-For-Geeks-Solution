
t = int(input())

while t > 0:
    n = int(input())
    s = input()
    l = len(s)
    pos = [0]*(l+10)
    cnt=0
    pos[cnt]=0
    cnt +=1
    for i in range(n):
        if s[i]=='a'or s[i]=='e'or s[i]=='i'or s[i]=='o'or s[i]=='u':
            pos[cnt]=i+1
            cnt+=1
    pos[cnt]=n+1
    if cnt <= 4:
        print("0")
        continue
    cnt1=0
    i=0

    while i+4<cnt:
        cnt1 += (pos[i+1]-pos[i])*(pos[i+4]-pos[i+3])
    print(cnt)
    
    t -= 1
