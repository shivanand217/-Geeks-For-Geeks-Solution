t = int(input())

while t > 0:
    l = [x for x in input().split()]
    str1 = str(l[0])
    str2 = str(l[1])

    ha1 = [0]*256
    ha2 = [0]*256

    for i in range(len(str1)):
        ha1[ord(str1[i])] += 1

    for i in range(len(str2)):
        ha2[ord(str2[i])] += 1

    cnt=0
    
    for i in range(256):
        if ha1[i] > 0 and ha2[i] > 0:
            cnt += (ha1[i] + ha2[i])
    cnt = (len(str1) + len(str2) - cnt)%5

    if cnt==1:
        print("LFAME")
    elif cnt==2:
        print("FLAME")
    elif cnt==3:
        print("FALME")
    elif cnt==4:
        print("FMALE")
    elif cnt==5:
        print("FEAML")
