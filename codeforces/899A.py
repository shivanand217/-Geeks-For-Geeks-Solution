n = int(input())
one=0
two=0

l = [int(x) for x in input().split()]
ans = 0

for x in l:
    if x == 1:
        one += 1
    else:
        two += 1
    
ans += min(one,two)

one -= ans
p = int(one/3)
ans += p

print(ans)

