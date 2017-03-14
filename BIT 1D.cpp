// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
/** 1d BIT: in this we give sum in range and update value effieciently with less memory usage in comparision with the segment tree **/
/** we give one extra index to the BITree in comp to the initial array an every time the getsum(index) function is called
    we have to return the sum of the array upto that index.

    algo: for get sum:
    we increase index by 1 i.e, index=index+1
    then we go to parent index until the index is greter than 0
    we get the parent index by removing the last set bit i.e, by formula index = index-(index & (-index))

    similarly for update operation
    we increase the index by 1 and then we update until the parent index is less equal to n
    parent is obtained in update using index=index+(index&(-index))
    **/

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

#define n 12

// set bit[0] to 0
int arr[n];
int BIT[n+1];

void initialise_bit()
{
    for(int i=0; i<=n; i++)
    {
        BIT[i]=0;
    }
}

int getsum(int index)
{
    index++;
    int sum=0;

    while(index > 0)
    {
        sum += BIT[index];
        index=index-(index&(-index));
    }
    return sum;
}

void update_bit(int index,int val)
{
    index++;

    while(index<=n)
    {
        BIT[index]+=val;
        index=index+(index&(-index));
    }
}

void solve()
{
    for(int i=0; i<n; i++)
    {
        update_bit(i,arr[i]);
    }
}

int main()
{
for(int i=0; i<n; i++)
{
    cin>>arr[i];
}

initialise_bit();
solve();

int query;cin>>query;

int l,r;

// for get sum up to index i from start use l as 0
while(query--)
{

cin>>l>>r;
int val = getsum(r)-getsum(l-1);
cout<<val<<endl;

}

return 0;
}
