
def solve(s):
    ans = []
    tmp = ""
    for i in s:
        if i == ' ':
            ans.append(tmp)
            tmp = ""
        else:
            tmp += i
    ans.append(tmp)
    i = 0
    j = len(ans) - 1
    while i < j:
        tmp = ans[i]
        ans[i] = ans[j]
        ans[j] = tmp
        i+=1
        j-=1
    s = ' '.join(ans)
    return s

s = "geeks quiz practice code"
s1 = solve(s)
print(s1)

s = "getting good at coding needs a lot of practice"
s1 = solve(s)
print(s1)
