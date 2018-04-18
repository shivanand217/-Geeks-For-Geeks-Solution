#include<bits/stdc++.h>

#define LLONG_MAX 9223372036854775807

using namespace std;

const int MAX = 1e4 + 5;

typedef pair<long long, int> pii;

/** marked array which determines which vertex is processed and which is not **/
bool marked[MAX];

/** our undirected weighted graph **/
vector<pii> graph[MAX];

/** swapping values using references **/
void _swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

class PriorityQueue {
    vector<pii> harr;
    int capacity;
    int heap_size;

public:
    /** constructor **/
    PriorityQueue(int capacity);

    void Minheapify(int);

    int parent(int i) {
        return floor(i/2);
    }

    /** left child **/
    int left(int i) {
        return (2*i + 1);
    }

    /** right child **/
    int right(int i) {
        return (2*i + 2);
    }

    pii extractMin();

    /** return top **/
    pii getMin() {
        return harr[0];
    }

    void insertKey(pii i);

    bool isEmpty();
};

PriorityQueue :: PriorityQueue(int capacity) {
    heap_size = 0;
    this->capacity = capacity;
    harr.resize(capacity);
}

bool PriorityQueue :: isEmpty() {
    if(heap_size == 0)
        return true;
    return false;
}

void PriorityQueue :: insertKey(pii k) {
    if(heap_size == capacity) {
        printf("Heap capacity full.\n");
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while( i != 0 && harr[parent(i)].first > harr[i].first ) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

pii PriorityQueue :: extractMin() {
    if(heap_size <= 0)
        return make_pair(LLONG_MAX, INT_MAX);

    if(heap_size == 1) {
        heap_size--;
        return harr[heap_size];
    }

    pii root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    Minheapify(0);

    return root;
}

void PriorityQueue :: Minheapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heap_size && harr[l].first < harr[smallest].first) {
        smallest=l;
    }

    if(r < heap_size && harr[r].first < harr[smallest].first) {
        smallest=r;
    }

    if(smallest != i) {
        swap(harr[i], harr[smallest]);
        Minheapify(smallest);
    }
}

long long prim(int x, int nodes) {
    /** priority queue for selecting the lowest cost edges each time **/
    /** In this case it is Min-Heap **/
    /**
        we can also take our priority queue(min_heap) from STL standard library
        priority_queue<pii, vector<pii>, greater<pii> > Q;
    **/
    memset(marked, false, sizeof(marked));

    PriorityQueue Q(nodes);
    int y;
    long long minimumCost = 0;
    pii p;

    /** pushing intially any arbitrary node to the priority queue(min heap) **/
    Q.insertKey(make_pair(0, x));

    /** we process our algorithm until the priority queue will become empty **/
    while( Q.isEmpty() == false ) {
        /** pop out the top = minimum weighted edge from priority queue **/
        p = Q.extractMin();

        /** x is our vertex attached to this edge **/
        x = p.second;

        /** if x was processed earlier don't go further **/
        if(marked[x] == true) {
            continue;
        }

        /** otherwise add this edge to our minimum spanning tree **/
        minimumCost += p.first;

        /** mark this vertex as it is now in our minimum spanning tree **/
        marked[x] = true;

        /**
            process all the adjacent edge of our current vertex and
            add only those to our priority queue which will not form
            a cycle with our current edges in the minimum spanning tree.
        **/
        for( int i = 0; i < graph[x].size(); i++ ) {
            /** y is the adjacent vertex **/
            y = graph[x][i].second;
            if( marked[y] == false ) {
                /** push that edge to our priority queue if it is not processed yet **/
                Q.insertKey(graph[x][i]);
            }
        }
    }

    return minimumCost;
}

int main() {

    /** Taking graph nodes to start with 1 **/
    int nodes, edges, x, y;
    long long weight, minimumCost;

    printf("Enter how many nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter how many edges in the graph: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++) {
        /** take input about each edge **/
        /** vertex1, vertex2 and weight attached to that edge **/
        scanf("%d %d %lld", &x, &y, &weight);

        /** The graph is undirected **/
        graph[x].push_back(make_pair(weight, y));
        graph[y].push_back(make_pair(weight, x));
    }

    /**
        get the required minimum cost for the spanning tree using prims algorithm
    **/

    minimumCost = prim(1, nodes);
    printf("The required minimum spanning tree cost is: %d\n", minimumCost);

    return 0;
}
