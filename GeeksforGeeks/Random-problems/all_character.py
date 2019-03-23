from collections import defaultdict

def solve(s, lst):   
    cnt1 = defaultdict()
    
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
    ans = []

    for l in lst:
        k = l
        cnt2 = defaultdict()
        for c in k:
            p = ord(c)
            if c.islower():
                p -= 97
            else:
                p -= 65
            if p in cnt2:
                cnt2[p] += 1
            else:
                cnt2[p] = 1
        flag = True
        for key in cnt1.keys():
            if key not in cnt2.keys():
                flag = False
                break
        if flag == True:
            ans.append(k)
    return ans

s = "sun"
lst = ["geeksforgeeks","unsorted","sunday","just","sss"]
ans = solve(s, lst)
print(ans)
