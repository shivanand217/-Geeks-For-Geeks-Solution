#include<bits/stdc++.h>
using namespace std;

/** complexity O(pow(b,d))  b is the branching factor d is the depth of the tree

/** we recursively search for the goal node until the depth is not going to be zero **/
/** IDDFS combines depth-first search's space-efficiency and breadth-first search's
completeness (when the branching factor is finite).
It is optimal when the path cost is a non-decreasing function of the depth of the node.[citation needed]
Since iterative deepening visits states multiple times,
it may seem wasteful, but it turns out to be not so costly,
since in a tree most of the nodes are in the bottom level, so it does not matter much if the upper levels are visited multiple times.[3]
The main advantage of IDDFS in game tree searching is that the earlier searches tend to improve the commonly used heuristics,
such as the killer heuristic and alpha-beta pruning,
so that a more accurate estimate of the score of various nodes at the final depth search can occur,
and the search completes more quickly since it is done in a better order.
For example, alpha-beta pruning is most efficient if it searches the best moves first.[3]

A second advantage is the responsiveness of the algorithm.
Because early iterations use small values for d,
they execute extremely quickly.
This allows the algorithm to supply early indications of the result almost immediately,
followed by refinements as  d increases.
When used in an interactive setting,
such as in a chess-playing program,
this facility allows the program to play at any time with the current best move found
in the search it has completed so far.
This can be phrased as each depth of the search recursively producing a better approximation of the solution,
though the work done at each step is recursive. This is not possible with a traditional depth-first search,
which does not produce intermediate results. **/

const int maxn = 1e5+2;

vector<int> graph; // this is my tree graph im calling this tree because we have to consider a root vertex in this algorithm
int goal_node;
int root_node;

int depth_[maxn];
int max_depth;

bool IDDFS(int root)
{
// run iteratively indefinitly
// indefinitely means it runs upto the depth of the tree
for(int depth=0; depth<=max_depth ; depth++)
{
    if(DLS(root,depth))
    {
        return true;
    }
}
return false;
}

bool DLS(int node,int depth)
{
    if (depth == 0 && node == goal_node)
    {
        return true;
    }
    // else recurse and search for the node

    if(depth > 0)
    {
        for(int i=0; i<graph[node].size(); i++)
        {
            if(DLS(graph[node][i],depth-1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    scanf("%d",&n); // no. of nodes

    int m;scanf("%d",&m); //edges

  scanf("%d%d",&root_node,&goal_node);
  int a,b;

  depth_[root_node] = 0;
  max_depth = 0;

  //read the edges
  // assuming the scanning of the edges in the form from root to depth
  for(int i=0; i<m; i++)
  {
      scanf("%d%d",&a,&b);
      graph[a].push_back(b);
      depth_[b] = depth_[a] + 1;
      if(max_depth < depth_[b])
           max_depth  = depth_[b];
  }

  if(IDDFS(root_node))
  {
      printf("Goal node is reached\n");
  }
  else
  {
      printf("Goal not Reached\n");
  }

return 0;
}
