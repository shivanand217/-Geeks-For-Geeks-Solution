/** 
   Implementation of Boruvka's algorithm for the computation of Minimum spanning tree
   Link to the Algorithm  https://en.wikipedia.org/wiki/Borůvka%27s_algorithm
**/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <climits>

#define maxx 100005

typedef vector<pair<long long, pair<int,int> > > vpi;

/** Our Minimum spanning tree obtained from the computation **/
vector<pair<long long, pair<int,int> > > MST;
 
struct graph {
    int nodes, edges;
    /** egdes to the graph **/
    vpi edge;
};

/** initilise graph having nodes and edges **/
void new_graph(int nodes, int edges) {
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    
    g->nodes = nodes;
    g->edges = edges;

    edge.resize(edges);
    return g;
}

/** 
    parent and rank matrix
    for union-find with path 
    compression
**/
int parent[maxx];
int rank_[maxx];

/** 
    initialize parent array to single component
    for each of the nodes and no cheapest edge
    attached to each of the component
**/
void init(int nodes, vector<int>& cheapest) {
    
    for(int i = 0; i < nodes; i++) {
        parent[i] = i;
        rank_[i] = 1;
        cheapest[i] = -1;
    }
}

/** find the root node of the existing component **/
int find_root(int random) {
   
    while(random != parent[random]) {
        parent[random] = parent[parent[random]];
        random = parent[random];
    }
    return random;
}

/** merge two components by comparing their rank values **/
void merge_(int a, int b) {

    int root1 = find_root(a);
    int root2 = find_root(b);

    /** Both are in the same component **/
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

/** Boruvka Algorithm for the computation **/

void boruvka(struct graph *g) {
    
    int nodes = g->nodes;
    int edges = g->edges;

    vector<int> cheapest;

    /** allocation memory equal to the total nodes we have 
        because initially every node is in single component
     **/
    cheapest.resize(nodes);

    /** initialise the parent and rank arrays **/
    init(nodes, cheapest);

    int total_trees = nodes;
    long long MSTweight = 0LL;

    /** 
        until we get a single tree as a component
        we will keep merging trees 
    **/
    while( total_trees > 1 ) {
        /** 
           going through each edge and update
           the cheapest edge attached to it 
        **/
       for(int i = 0; i < edges; i++) {

           int a = g->edge[i].second.first;
           int b = g->edge[i].second.second;

           /** find the root nodes of these components **/
           int root1 = find_root(a);
           int root2 = find_root(b);

           /** If both are in the same components **/
           if( root1 == root2 ) {
               continue;

           } else {
               /** 
                   cheapest[] vector is holding the indices
                   of the edge that is current cheapest edge
                   attached to this component 
                **/ 
               if(cheapest[root1] == -1 || g->edge[cheapest[root1]].first > g->edge[i].first) {
                  cheapest[root1] = i; 
               }

               if(cheapest[root2] == -1 || g->edge[cheapest[root2]].first > g->edge[i].first ) {
                   cheapest[root2] = i;
               }
           }
       }

       /** Adding the cheapest edge to our minimum spanning tree **/
       for( int i = 0; i < nodes; i++ ) {
            /** 
                if this node has some cheapest 
                component attached to it 
            **/
            if( cheapest[i] != -1 ) {
                int root1 = find_root(edge[cheapest[i]].second.first);
                int root2 = find_root(edge[cheapest[i]].second.second);

                if( root1 == root2 ) {
                    continue;   
                }
                
                /** Adding this weight to our MST component **/
                MSTweight += edge[cheapest[i]].first;

                p = make_pair(g->edge[cheapest[i]].first,make_pair(g->edge[cheapest[i]].second.first,g->edge[cheapest[i]].second.second));
                MST.push_back(p);

                merge_(root1, root2);

                total_trees -= 1;
            } 
       }
    }

    printf("Weight of Minimum spanning tree is: %lld\n", MSTweight);
}

int main() {

    int nodes , edges;
    printf("Total nodes in graph: ");
    scanf("%d",&nodes);
    putchar('\n');

    printf("Total edges in the graphs: ");
    scanf("%d",&edges);
    putchar('\n');

    struct graph *g = new_graph(nodes, edges);


    return 0;
}



