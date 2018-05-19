#include<bits/stdc++.h>
using namespace std;

/** Number of runs for the test data generated **/
#define RUN 1

/**
   We have to restrict our number of nodes constraints because of
   the memory consumption in the representation of the graph
   as in this case the graph generated must be represented using adjacency list
**/
#define MAX_VERTICES 1004

/** Define the maximum number of edges **/
#define MAX_EDGES 500001

/** Define the maximum weight of an edge **/
#define MAXWEIGHT 10000

int adjacency_list[MAX_VERTICES][MAX_VERTICES];

void init(int NUM) {
    for(int i = 0; i < NUM; i++) {
        for(int j = 0; j < NUM; j++) {
            adjacency_list[i][j] = 0;
        }
    }
}

int main() {
    int NUM;
    int NUMEDGE;

    set<pair<int, int> > container;
    set<pair<int, int> > :: iterator it;

    freopen("Test_Cases_Undirected_Weighted_Graph_Adjacency_list10.in", "w", stdout);

    /** For changing initial seed values every time **/
    srand(time(NULL));

    for (int i=1; i <= RUN; i++)
    {
        NUM = 1 + rand() % MAX_VERTICES;

        /**
            Define the maximum number of edges of the graph
            Since the most dense graph can have N*(N-1)/2 edges
            where N =  number of vertices in the graph
        **/
        NUMEDGE = 1 + rand() % MAX_EDGES;

        while(NUMEDGE > NUM*(NUM-1)/2)
            NUMEDGE = 1 + rand() % MAX_EDGES;

        /** number of vertices and edges randomly generated **/
        printf("%d %d\n", NUM, NUMEDGE);

        init(NUM);

        for (int j = 1; j <= NUMEDGE; j++)
        {
            int a = rand() % NUM;
            int b = rand() % NUM;
            pair<int, int> p = make_pair(a, b);
            pair<int, int> reverse_p = make_pair(b, a);

            /**
                Searching for a random "new" edge everytime
                In a tree the edge (a, b) is same
                as the edge (b, a)
            **/

            while (container.find(p) != container.end() || container.find(reverse_p) != container.end())
            {
                a = rand() % NUM;
                b = rand() % NUM;

                /** ignoring the matrix[x][x] Case because graph has no self loop **/
                if(a == b) {
                    continue;
                }

                p = make_pair(a, b);
                reverse_p = make_pair(b, a);
            }
            container.insert(p);
        }

        for(it = container.begin(); it != container.end(); ++it)
        {
            int wt = 1 + rand() % MAXWEIGHT;
            adjacency_list[it->first][it->second] = wt;
            adjacency_list[it->second][it->first] = wt;
        }

        for(int i = 0; i < NUM; i++) {
            for(int j = 0; j < NUM; j++) {
                printf("%d ",adjacency_list[i][j]);
            }
            printf("\n");
        }

        container.clear();
        printf("\n");
    }

    fclose(stdout);

    return(0);
}
