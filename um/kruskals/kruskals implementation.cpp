#include<bits/stdc++.h>
using namespace std;

/** maximum nodes in the graph **/
const int MAX = 1e5 + 10;

typedef pair<long long, pair<int,int> > pii;

int parent[MAX], nodes, edges;
int _rank[MAX];

/** Merge function of our merge sort **/
void _merge(pair<long long, pair<int,int> > EDGE[], int l, int mid, int r) {
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    pii Left[n1], Right[n2];

    /** Copying original data **/
    for(int i = 0; i < n1; i++) {
        Left[i] = EDGE[l + i];
    }
    for(int i = 0; i < n2; i++) {
        Right[i] = EDGE[mid + 1 + i];
    }

    i = 0;
    j = 0;
    k = l;

    /** Merging edges according to their weights **/
    while(i < n1 && j < n2) {
        if(Left[i].first <= Right[j].first) {
            EDGE[k] = Left[i];
            i++;
        } else {
            EDGE[k] = Right[j];
            j++;
        }
        k++;
    }

    /** Copy the remaining values **/
    while(i < n1) {
        EDGE[k++] = Left[i++];
    }
    while(j < n2) {
        EDGE[k++] = Right[j++];
    }
}

void merge_sort(pair<long long, pair<int,int> > EDGE[], int l, int r) {
    if(l < r) {
        int mid = (l+r)/2;
        /** recur for left part **/
        merge_sort(EDGE, l, mid);
        /** recur for right part **/
        merge_sort(EDGE, mid+1, r);
        /** finally merge left and right part **/
        _merge(EDGE, l, mid, r);
    }
}

/** initialize starting parent to itself **/
void initialise() {
    for(int i = 1; i <= nodes; i++) {
        /** set parent of each vertex to itself **/
        parent[i] = i;
        /** set rank to 1 initially of each vertex **/
        _rank[i] = 1;
    }
}

/** for finding parent of a node **/
int find_root(int x) {
    /**
        while we do not reached the vertex who is parent of itself recur further for parent of parents
        we are here doing union by path compression to reduce our complexity
    **/
    while(parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    /** return the parent node of this component **/
    return x;
}

/** union function of disjoint set **/
void _union(int x, int y) {
    /** find roots of different component **/
    int p = find_root(x);
    int q = find_root(y);

    /** if both have same root node, no need to do union operation **/
    if(p == q) {
        return;
    }
    /**
        otherwise do union operation according to rank of their root nodes
    **/
    if(_rank[p] > _rank[q]) {
        _rank[q] += _rank[p];
        parent[p] = q;
    } else {
        _rank[p] += _rank[q];
        parent[q] = p;
    }
}

long long kruskal(pair<long long, pair<int,int> > EDGE[]) {
    int node1, node2;
    long long cost, minimumCost = 0;
    int root1, root2;

    for(int i= 0; i < edges; i++) {
        node1 = EDGE[i].second.first;
        node2 = EDGE[i].second.second;
        cost  = EDGE[i].first;

        root1 = find_root(node1);
        root2 = find_root(node2);

        if(root1 != root2) {
            minimumCost += cost;
            _union(node1, node2);
        }
    }
    return minimumCost;
}

int main() {
    int node1 , node2;
    long long weight, cost, minimumCost;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    pair<long long, pair<int, int> > EDGE[edges];

    /** initialize our parent and _rank array for processing union-find operation **/
    initialise();

    /** take edges as input **/
    for(int i = 0; i < edges; i++) {
        scanf("%d", &node1);
        scanf("%d", &node2);
        scanf("%lld", &weight);

        EDGE[i] = make_pair(weight, make_pair(node1, node2));
    }

    for(int i = 0; i < edges; i++) {
        printf("%d ", EDGE[i].first);
    }
    putchar('\n');

    /** Using merge_sort() to sort edges in increasing order of weight **/
    merge_sort(EDGE, 0, edges - 1);

    for(int i = 0; i < edges; i++) {
        printf("%d ", EDGE[i].first);
    }

    minimumCost = kruskal(EDGE);
    printf("Total Cost of our minimum spanning tree is %lld\n", minimumCost);

    return 0;
}
