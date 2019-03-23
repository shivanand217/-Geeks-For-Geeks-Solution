

from collections import defaultdict

cnt = defaultdict()

s = input()
c = input()
count = int(input())
cnt[c] = 0
ans = ""
flag = True

for x in s:
    if x == c and flag == True:
        cnt[c] += 1
        if cnt[c] == count:
            flag = False
            continue
    
    if flag == False:
        ans += x

print(ans) 
        