
def run_length_encoding(s):
    tmp = ""
    cnt = 0
    i = 0
    p = len(s) - 1
    while i < p:
        cnt = 0
        c = s[i]
        if s[i] == s[i+1]:
            while (i < p) and (s[i] == s[i+1]):
                cnt += 1
                i += 1
            cnt += 1
            i += 1
            tmp += c
            tmp += str(cnt)
            cnt = 0
        else:
            cnt += 1
            tmp += s[i]
            tmp += str(cnt)
            i += 1
    
    cnt = 0
    if(s[p] != s[p-1]):
        cnt += 1
        tmp += s[p]
        tmp += str(cnt)
    else:
        pass
    return tmp

s = "wwwwaaadexxxxx"
s1 = run_length_encoding(s)
print(s1)

s = "geeksforgeeks"
s1 = run_length_encoding(s)
print(s1)