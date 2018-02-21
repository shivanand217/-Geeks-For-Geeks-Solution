from collections import defaultdict

MAX = 256

class Freq(object):
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq

def swap(x, y):
    return y ,x

def toList(s):
    lst = list(s)
    return lst

def toString(lst):
    ''.join(lst)

#~~~~~~~~~~~~~ below is the heapify procedure ~~~~~~~~~~#

def maxHeapify( freq, i, heap_size ):
    l = 2*i + 1
    r = 2*i + 2
    largest = i
    if l < heap_size && freq[l].freq > freq[i].freq:
        largest = l
    if r < heap_size && freq[r].freq > freq[largest].freq:
        largest = r
    if largest != i:
        tmp = freq[i]
        freq[i] = freq[largest]
        freq[largest] = tmp
        maxHeapify( freq, largest, heap_size )

def buildHeap( freq, n ):
    i = (n - 1)/2
    while i >= 0:
        maxHeapify(freq, i, n)
        i -= 1

def extractMax(freq, heap_size):
    top = freq[0]
    if heap_size > 1:
        freq[0] = freq[heap_size-1]
        maxHeapify(freq, 0, heap_size - 1)
    return top

def rearrange(s, d):
    n = len(s)
    freq = []
    for x in range(MAX):
        freq.append(Freq(0,0))

    m = 0
    for i in range(n):
        x = ord(s[i])
        if freq[x].freq == 0:
            freq[x].char = chr(x)
            