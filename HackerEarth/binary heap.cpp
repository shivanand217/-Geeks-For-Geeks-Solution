#include<bits/stdc++.h>
using namespace std;

/** swapping values using references **/
void _swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

class Minheap {
    int *harr;
    int capacity;
    int heap_size;
public:
    Minheap(int capacity);

    void MinHeapify(int);

    int parent(int i) {
        return floor(i/2);
    }

    int left(int i) {
        return (2*i + 1);
    }

    int right(int i) {
        return (2*i + 2);
    }

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getMin() {
        return harr[0];
    }

    void deleteKey(int i);

    void insertKey(int k);
};

Minheap :: Minheap(int capacity) {
    heap_size = 0;
    this->capacity = capacity;
    harr = new int[capacity];
}

void Minheap:: insertKey(int k) {
    if(heap_size == capacity) {
        printf("Heap capacity full.\n");
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while(i != 0 && harr[parent(i)] > harr[i]) {
        _swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void Minheap :: decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while(i != 0 && harr[parent(i)] > harr[i]) {
        _swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int Minheap:: extractMin() {
    if(heap_size <= 0)
        return INT_MAX;
    if(heap_size == 1) {
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}

void Minheap:: deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

void Minheap:: MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && harr[l] < harr[i]){
        smallest = l;
    }
    if(r < heap_size && harr[r] < harr[smallest]){
        smallest = r;
    }
    if(smallest != i) {
        _swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int main() {
    Minheap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    cout<<h.extractMin()<<endl;
    h.deleteKey(1);

    return 0;
}
