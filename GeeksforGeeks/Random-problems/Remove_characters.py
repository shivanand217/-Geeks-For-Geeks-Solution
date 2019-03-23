'''
Write an efficient function that takes two strings as arguments 
and removes the characters from first string which are present in second string (mask string).
'''

from collections import defaultdict

def solve(s1, s2):
    cnt1 = defaultdict()
    cnt2 = defaultdict()
    for x in s2:
        if x not in cnt2.keys():
            cnt2[x] = 1
    
    ans = ""

    for x in s1:
        if x not in cnt2.keys():
            ans += x
    return ans
        
s1 = input()
s2 = input()

s1 = solve(s1,s2)
print(s1)