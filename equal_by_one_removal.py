
from collections import defaultdict

def solve(s):

    cnt = defaultdict()
    for x in s:
        if x not in cnt.keys():
            cnt[x] = 1
        else:
            cnt[x] += 1
        

s = input()

if solve(s):
    print("Yes")
else:
    print("No")