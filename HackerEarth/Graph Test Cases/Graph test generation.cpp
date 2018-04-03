/** Program to generate test case for a weighted undirected graph(Dense) **/

#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

#define RUN 1

#define MAX_VERTICES 1000

/** for maximum undirected weighted dense graph edges will be (n*(n-1))/2 **/
#define MAX_EDGES 1000000

/** maximum edge weight **/
#define MAX_WEIGHT 1000

int main() {
    set<pair<int,int> > container;
    set<pair<int,int> > :: iterator it;

    /**
    if( access("Test_cases_undirected_weighted_graph.in", F_OK) != -1 ) {
        file_name = default_;
        file_name += (file + '0');
        file_name += ".in";
        cout<<file_name<<endl;
        return 0;
        /**
        while(1) {
            if( access(file_name, F_OK) != -1 ) {
                file_name = default_;
                file++;
                file_name += (file + '0');
                file_name += ".in";
            } else {
                break;
            }
        }
    }
    **/

    freopen("Test_cases_undirected_weighted_graph5.in", "w", stdout);

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
            while(container.find(p) != container.end() ||
                  container.find(reverse_p) != container.end()) {

                a = rand() % NUM;
                b = rand() % NUM;
                p = make_pair(a,b);
                reverse_p = make_pair(b,a);
            }
            container.insert(p);
        }

        for(it = container.begin(); it != container.end(); ++it) {
            int weight = 1 + rand() % MAX_WEIGHT;
            printf("%d %d %d\n", it->first, it->second, weight);
        }

        container.clear();
        printf("\n");
    }

    fclose(stdout);

    return 0;
}

