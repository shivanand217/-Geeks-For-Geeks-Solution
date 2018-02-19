
a = [0]*33000

def solve(num):
    steps = 0

    while num != 1:
        if num %2 == 1:
            num = 3*num + 1
        else:
            num /= 2
        steps += 1
        
    return steps

def pre():
    a[1]=0
    a[2]=1
    for i in range(3,33000):
        a[i] = solve(i)

pre()
t = int(input())

while t > 1:
    n = int(input())
    print(a[n])
    
