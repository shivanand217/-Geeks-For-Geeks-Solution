// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O((maxn + Q) * log(maxn)) // Q will be the query(how many)

/** question is to find the maximum number of divisors a number has in a given range **/

#include<bits/stdc++.h>
using namespace std;

#define maxn 100005
#define INF 999999
#define ll long long

int smallest_prime[maxn];
int divisors[maxn];
int segment_tree[4 * maxn];

// finding smallest prime divisors of all the numbers in the given range(1, maxn)
void smallest_prime_divisors()
{
    memset(smallest_prime, INF, sizeof(smallest_prime));

    for(ll i=2; i<maxn; i++)
    {
        if(smallest_prime[i] == INF)
        {
            smallest_prime[i] = i;

            for(ll j=i*2; j<maxn; j+=i)
            {
                if(smallest_prime[j] > i)
                {
                    smallest_prime[j] = i;
                }
            }
        }
    }
}

// now we find the divisors of a number in the given range
// building divisors array
void divisors_()
{
for(int i=1; i<maxn; i++)
{
    divisors[i] = 1;
    int n=i, p=smallest_prime[i],k=0;

    while(n > 1)
    {
        n/=p;
        k++;

        if(smallest_prime[n] != p)
        {
            divisors[i] = divisors[i] * (k+1);
            k = 0;
        }

        p = smallest_prime[n];
    }
}

}

//building the segment tree for the divisors array
void build_segmentTree(int node, int a, int b)
{
    // leaf node
    if(a == b)
    {
        segment_tree[node] = divisors[a];
        return;
    }

    // building left and right subtree
    build_segmentTree(2*node , a, ((a+b)/2));
    build_segmentTree(2*node+1, ((a+b)/2) + 1, b);

    //store the maximum of left and right in the current node
    segment_tree[node] = max(segment_tree[2*node], segment_tree[2*node+1]);
}

int query(int node , int a ,int b, int l, int r)
{
    // if current node is completely disjoint
    if(l > b || r < a)
    {
        return -1;
    }

    // if matches exactly with the current node
    if(a >= l && b <= r )
    {
        return segment_tree[node];
    }

return max(query(2 * node, a, (a + b) / 2, l, r),
               query(2 * node + 1, ((a + b) / 2) + 1, b,l,r));
}

int main()
{
    smallest_prime_divisors();
    divisors_();

    build_segmentTree(1,1, maxn-1);


    int ans1 = query(1, 1, maxn-1, 1, 100);
    cout<<ans1<<endl;

    return 0;
}
