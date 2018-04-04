/** Program to generate test case for a weighted directed graph (Dense graph) **/
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

#define RUN 1

#define MAX_VERTICES 1000

/** maximum edges for directed weighted dense graph will be (n*(n-1))/2 **/
#define MAX_EDGES 1000000

#define MAXWEIGHT 100000

int main() {
    set<pair<int,int> > container;
    set<pair<int,int> > :: iterator it;

    freopen("Test_cases_directed_weighted_graph5.in", "w", stdout);

    /** set initial seed to NULL **/
    srand( time(NULL) );

    int NUM; /** number of vertices **/
    int NUMEDGE; /** number of edges **/

    for( int i=1; i <= RUN; i++ ) {
        NUM = 1 + rand() % MAX_VERTICES;
        /**
            Defining maximum number of edges of the graph
            Since the most dense graph can have n*(n-1)/2 edges
        **/
        NUMEDGE = 1 + rand() % MAX_EDGES;

        while( NUMEDGE > NUM*(NUM-1)/2 ) {
            NUMEDGE = 1 + rand() % MAX_EDGES;
        }

        printf("Vertices: %d, Edges: %d\n", NUM, NUMEDGE);

        vector<pair<int,int> > graph[NUM];

        /** printing edges of the form (a, b) **/
        for(int j=1; j <= NUMEDGE; j++) {
            int a = rand() % NUM;
            int b = rand() % NUM;

            pair<int, int> p = make_pair(a, b);
            pair<int, int> reverse_p = make_pair(b, a);

            /** Search for a random new edge everytime
                In a tree the edge (a, b) is same as edge (b, a)
                If any pair existed in the current graph then
                remain searching for the new pair otherwise
                add this pair in the graph.
            **/
            while( container.find(p) != container.end() ||
                   container.find(reverse_p) != container.end() ) {
                a = rand() % NUM;
                b = rand() % NUM;
                p = make_pair(a,b);
                reverse_p = make_pair(b,a);
            }
                container.insert(p);
        }

        printf("Edges are: \n");

        for(it = container.begin(); it != container.end(); ++it) {
            int weight = 1 + rand() % MAXWEIGHT;
            graph[it->first].push_back(make_pair(it->second,weight));
            printf("%d - %d - wt=%d\n", it->first, it->second, weight);
        }

        container.clear();
        printf("\n");
    }

    fclose(stdout);

    return 0;
}

