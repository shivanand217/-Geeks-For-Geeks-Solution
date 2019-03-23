from collections import defaultdict

def solve(n, seq):
    flag = True
    # slot = [0] * (n + 10)
    freq = defaultdict()

    # refer to next free slot
    i = 1
    p = len(seq)
    j = 0

    while j < p:
        c = seq[j]
        if i > n:
            flag = False
            break
        if c in freq.keys():
            if freq[c] == 1:
                freq[c] = 0
                i -= 1
            else:
                freq[c] = 1
                i += 1
        if c not in freq.keys():
            freq[c] = 1
            i += 1
        j += 1

    if flag == True:
        return 0
    else:
        return 1 


# number of computers
n = int(input())
seq = input()

if solve(n, seq):
    print("Satisfied")
else:
    print("Not Satisfied")