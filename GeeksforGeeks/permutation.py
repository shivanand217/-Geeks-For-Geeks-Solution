
def permute(s, l, r):
    if l == r:
        if s == None:
            pass
        else:
            print(s)
    else:
        for i in range(l, r):
            #swapping characters 
            lst = list(s)
            tmp=lst[l]
            lst[l]=lst[i]
            lst[i]=tmp
            s=''.join(lst)
            permute(s, l+1, r)
            #backrack
            lst = list(s)
            tmp=lst[l]
            lst[l]=lst[i]
            lst[i]=tmp
            s=''.join(lst)
s = "ABC"
l = 0
r = len(s)
print(permute(s, l, r))