
from collections import defaultdict

def solve(s):
    cnt = defaultdict()
    
    for x in s:
        if x not in cnt:
            cnt[x] = 1
        else:
            cnt[x] += 1

    fir = 0
    sec = 0
    cnt2 = defaultdict()
    tot = 0

    for x in cnt.values():
        if x not in cnt2:
            cnt2[x] = 1
        else:
            cnt2[x] += 1

s = input()
if solve(s):
    print("Possible")
else:
    print("Not possible")