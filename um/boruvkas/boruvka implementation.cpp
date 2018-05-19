#include<bits/stdc++.h>
using namespace std;

/** maximum vertex our graph should contain **/
#define MAX 10005

int Vertex, Edge;

/** Subset of edges to contain our union find data structure
    pair<int, int> containing <parent, rank> **/
vector< pair<int,int> > subset(MAX);

/** Corner vertex attached to each of our edges **/
vector< pair< int, pair<int, int> > > edge(MAX);

int u, v, weight;

/** initialize our union-find data structure **/
void initialize(int* cheapest_edge) {
    /** Initialising every vertex into single component **/
    for(int i=0; i < Vertex; i++) {
        /** Initially set every vertex parents to itself **/
        subset[i].first = i;
        /** rank will be zero iniially **/
        subset[i].second = 0;
        /** cheapest edge attached to each vertex is null **/
        cheapest_edge[i] = -1;
    }
}

/** find function of our union-find data structure , for finding parent node of our component **/
int find_root(int vertex) {
    while( subset[vertex].first != vertex ) {
        subset[vertex].first = subset[subset[vertex].first].first;
        vertex = subset[vertex].first;
    }
    return vertex;
}

/** Union function of out union-find data structure **/
/** using path compression by rank **/
void union_( int v1, int v2 ) {
    int root1 = find_root(v1);
    int root2 = find_root(v2);
    if(subset[root1].second < subset[root2].second) {
        subset[root1].first = root2;
    } else if(subset[root1].second > subset[root2].second) {
        subset[root2].first = root1;
    } else {
        subset[root2].first = root1;
        subset[root1].second++;
    }
}

/** our algorithm **/
void Boruvka(int* cheapest_edge) {
    /** Initialize total number of trees count initially equal
        to the total number of vertices **/
    int trees_count = Vertex;
    /** initial weight of our minimum spanning tree **/
    int mstWeight = 0;

    while( trees_count > 1 ) {
        /** traversing through every edge
            and updating cheapest edge attached to the vertices **/
        for(int i = 0; i < Edge; i++) {
            int vertex1 = find_root(edge[i].second.first);
            int vertex2 = find_root(edge[i].second.second);

            /** if both the vertex are in same component don't consider this edge **/
            if(vertex1 == vertex2) {
                continue;
            } else {
                if( cheapest_edge[vertex1] == -1 || (edge[cheapest_edge[vertex1]].first > edge[i].first ) ) {
                    cheapest_edge[vertex1] = i;
                }

                if( cheapest_edge[vertex1] == -1 || ( edge[cheapest_edge[vertex2]].first > edge[i].first ) ) {
                    cheapest_edge[vertex2] = i;
                }
            }
        }

        /** adding the cheapest_edges to the MST **/
        for(int i = 0; i < Vertex; i++) {
            if(cheapest_edge[i] != -1) {
                int vertex1 = find_root(edge[cheapest_edge[i]].second.second);
                int vertex2 = find_root(edge[cheapest_edge[i]].second.first);

                if(vertex1 == vertex2) {
                    continue;
                } else {
                    /** include this into our minimum spanning tree **/
                    mstWeight += edge[cheapest_edge[i]].first;
                    printf("%d - %d is included in MST\n", edge[cheapest_edge[i]].second.first, edge[cheapest_edge[i]].second.second);

                    /** doing union of vertex1 and vertex2 **/
                    union_(vertex1, vertex2);
                    trees_count--;
                }
            }
        }
    }

    printf("Weight of required mst is %d \n", mstWeight);
}

int main() {

    printf("Give no. of vertex in the graph: ");
    scanf("%d", &Vertex);

    printf("Give no. of edges in the graph: ");
    scanf("%d", &Edge);

    /** This holds the data of what is the
        next cheapest edge that is attached
        to each subset **/
    int cheapest_edge[Vertex];

    initialize(cheapest_edge);
    pair<int, pair<int,int> > p;

    /** take input edges and their weight **/
    for( int i =0; i < Edge; i++ ) {
        scanf("%d %d %d", &u, &v, &weight);
        p = make_pair(weight, make_pair(u, v));
        edge[i] = p;
    }

    Boruvka(cheapest_edge);

    /**for(int i = 0; i < Vertex; i++) {
        printf("%d ", cheapest_edge[i]);
    }   putchar('\n'); **/


    return 0;
}
