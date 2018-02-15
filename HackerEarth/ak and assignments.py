def solve(l):
    ans = []
    for s in l:
        a = ""
        i = len(s)-1
        while i>=0:
            a += s[i]
            i -= 1
        ans.append(a)
    for i in range(len(ans)):
        print(ans[i],end=" ")

s = input()
l = list(s.split(' '))

ans = solve(l)

