// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** In this problem we are using bitset container in c++
    we first create bit vector upto the maximum sum that can be asked in the query
    but this method is space consuming because we have to first store all the query
    then we can continue the process... there after we do bitwise OR with the array and existing bit vector
    if any bit is on that means that we can get the sum of that bit with subset of array elements **/

// this works only when we initialize the maximum bit length of bit vector
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

#define maxs 1000

const int maxn = 105;
int arr[maxn];
int qu[maxn];

//static int k;
int n,query;

void solve()
{
    bitset<maxs> bit;
    bit[0]=1; // set the 0th bit as 1 because there always sum of zero is obtained from any array by choosing no elements

    for(int i=0; i<n; i++)
    {
        bit = bit | bit<<arr[i];
    }

    for(int i=0; i<query ; i++)
    {
        if(bit[qu[i]+1] == 1)
            cout<<"subset sum of "<<qu[i]<<" exist"<<endl;
        else
            cout<<"not exist"<<endl;
    }
}

int main()
{
//int n,query;

read(n)
read(query)

for(int i=0; i<n; i++)
{
    read(arr[i])
}

for(int i=0; i<query; i++)
{
    read(qu[i])
}

solve();

return 0;
}
