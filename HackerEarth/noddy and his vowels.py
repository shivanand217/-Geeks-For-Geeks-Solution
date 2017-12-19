t = int(input())
while t > 0:
    a = 0
    e = 0
    i = 0
    o = 0
    u = 0
    s = input()
    for p in range(len(s)):
        if s[p]=='a':
            a=1
        if s[p]=='e':
            e=1
        if s[p]=='i':
            i=1
        if s[p]=='o':
            o=1
        if s[p]=='u':
            u=1
    if a==1 and e==1 and i==1 and o==1 and u==1:
        print("YES")
    else:
        print("NO")
    t -= 1
            
            
    
