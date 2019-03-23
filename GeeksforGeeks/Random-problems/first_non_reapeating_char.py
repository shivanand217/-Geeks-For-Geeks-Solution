from collections import defaultdict

# optimization is to store the index also with the cnt of character
# it will do in single traversal
def solve(s):
    cnt1 = defaultdict()
    cnt2 = defaultdict()
    index = 0
    for i in s:
        p = ord(i)
        if i.islower():
            p -= 97
        else:
            p -= 65
        if p in cnt1:
            cnt1[p] += 1
        else:
            cnt1[p] = 1
        if p not in cnt2:
            cnt2[p] = index
        # storing the first found index
        index += 1
    ans = -1
    for i in cnt2.keys():
        if cnt1[i] == 1:
            if ans == -1:
                ans = cnt2[i]
            else:
                if ans > cnt2[i]:
                    ans = cnt2[i]
    return ans

s="geeksforgeeks"
ans = solve(s)
print(ans)
print(s[ans])