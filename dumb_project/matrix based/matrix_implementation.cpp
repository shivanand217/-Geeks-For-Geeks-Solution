/** This algorithm consists of adjacency matrix based implementation **/
/** Graph is weighted and undirected having only positive weighted edge **/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

/**
   We have to restrict our vertex constraints because of
   the memory consumption in the representation of the graph with adjacency matrix.
   as in this algorithm the graph is represented using adjacency matrix.
**/

#define maxx 1004

/** Original adjacency matrix of the graph **/
long long matrix[maxx][maxx];

int nodes;
int edges;

/** our required minimum spanning tree **/
vector<pair<long long, pair<int,int> > > MST;

/** initial unmarked nodes **/
bool mark[maxx];

/** calculated weight of MST **/
long long MST_weight;

/** parent and rank array for finding cycles **/
int parent[maxx];
int rank_[maxx];

/** Initialize our graph **/
void init() {
    for(int i = 0; i < nodes; i++) {
        parent[i] = i;
        rank_[i] = 1;
    }
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            matrix[i][j] = 0;
        }
    }
}

/** find the root node of a component **/
int find_root(int random) {
    while(parent[random] != random) {
        parent[random] = parent[parent[random]];
        random = parent[random];
    }
    return random;
}

/** merge two components **/
void _merge(int a, int b) {
    int root1 = find_root(a);
    int root2 = find_root(b);

    if(root1 == root2) {
        return;
    }

    if(rank_[root1] > rank_[root2]) {
        parent[root1] = root2;
        rank_[root2] += rank_[root1];
    } else {
        parent[root2] = root1;
        rank_[root1] += rank_[root2];
    }
}

/**
    For finding the next minimum weighted edge
    It may return an edge which is creating cycle
    with our current Minimum spanning tree.
**/
pair<long long,pair<int,int> > find_next_minimum() {
    pair<long long, pair<int,int> > p;
    long long weigh = LLONG_MAX;
    int x,y;

    /** Find the minimum edge from the remaining edges left to consider **/
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            if( matrix[i][j] != 0 ) {
                if( weigh > matrix[i][j] ) {
                    weigh = matrix[i][j];
                    x = i;
                    y = j;
                }
            }
        }
    }

    /** if we run out of edges **/
    if( weigh == LLONG_MAX ) {
        p = make_pair(0LL, make_pair(0,0));
        return p;
    }

    p = make_pair(weigh, make_pair(x,y));
    return p;
}

int main() {
    int x , y, wt;

    freopen("input7.in", "r", stdin);
    freopen("output7.out", "w", stdout);

    /** input total nodes **/
    scanf("%d", &nodes);

    /** Input total edges **/
    scanf("%d", &edges);

    /** initialize the graph **/
    init();
    pair<long long, pair<int,int> > p;

    /** taking all the edges input via adjacency matrix **/
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            scanf("%d", &wt);
            matrix[i][j] = wt;
            matrix[j][i] = wt;
        }
    }

    int total_marked = 0;
    MST_weight = 0LL;
    int ff,ss;

    /** processing all the edges of the graph **/
    while(1) {
        p = find_next_minimum();

        /** If we runs out of all the edges then we are done **/
        if( p.first == 0LL ) {
            break;
        }

        ff = p.second.first;
        ss = p.second.second;

        int root1 = find_root(ff);
        int root2 = find_root(ss);

        /** If this edge is creating a cycle, Ignore this edge **/
        if(root1 == root2) {
            matrix[ff][ss] = 0;
            matrix[ss][ff] = 0;
            continue;
        }

        /** add this edge in our Minimum spanning tree **/
        p = make_pair(matrix[ff][ss], make_pair(ff,ss));
        MST.push_back(p);

        MST_weight += matrix[ff][ss];

        /** Clear the edge **/
        matrix[ff][ss] = 0;
        matrix[ss][ff] = 0;

        _merge(ff, ss);
    }

    /** print the edges of our Minimum spanning tree and the obtained weight **/
    printf("MST weight is : %lld\n", MST_weight);

    printf("All the edges\n");
    for(int i = 0; i < MST.size(); i++) {
        p = MST[i];
        printf("%d %d %lld\n", p.second.first, p.second.second, p.first);
    }

    return 0;
}
