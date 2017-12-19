
t = int(input())

while t > 0:

    h = [0]*26

    s = input()
    
    for i in range(len(s)):
        if s[i] >= 'a' and s[i] <= 'z':
            h[ord(s[i]) - 97] += 1
        if s[i] >= 'A' and s[i] <= 'Z':
            h[ord(s[i]) - 65] += 1

    an = True

    c = 97
    while c <= 122:
        if h[c - 97] == 0:
            an = False
            q = chr(c)
            print(q)
            break
        else:
            c += 1

    if an == True:
        print("~")

    t -= 1
        
