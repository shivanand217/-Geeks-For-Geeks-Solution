s = input()

p = ['1','2','3','4','5','6','7','8','9']
k = []

length = len(p)

for i in s:
    if i in p:
        k.append(int(i))

kp = sum(k)
print(kp)

