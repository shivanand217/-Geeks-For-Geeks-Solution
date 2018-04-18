// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// COMPLEXITY: O(sqrt(n))

/**
this is in between linear search and binary search
when we search from start we set the jump size equal to sqrt(arr.size())
then at time when we reach the index whose value is greater than the value we go for previous block
then start searching linearly from there this leads to O(n/m + (m-1)) comparisions which is minimum for m=sqrt(n)
**/


/** array should be already sorted if not comlexity O(nlogn + sqrt(n)) **/

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val)
#define print(val) printf("%d",val)
#define scan(val) scanf("%lld",&val)
#define show(val) printf("%lld",val)
#define ll long long
using namespace std;

const int maxn = 1e5+2;
int n;
ll arr[maxn];

bool do_jump_search(int val)
{
    int jump_size= floor(sqrt(n));

    jump_size--;
    int prev=0;
    int last=prev;

    while(arr[prev+jump_size] <= val)
    {
        last=prev;
        prev=prev+jump_size;
        if(arr[prev] == val)
            return true;
    }

    for(int i=last; i<n; i++)
    {
        if(arr[i] == val)
            return true;
    }
    return false;
}

int main()
{
    int test=5;

    while(test--)
    {
    //int n;
    read(n);

    for(int i=0; i<n; i++)
    {
        read(arr[i]);
    }

    int search_val;
    read(search_val);

    if(do_jump_search(search_val))
    {
        cout<<"value is in array"<<endl;
    }
    else
    {
        cout<<"value is not in array"<<endl;
    }

    }
    return 0;
}
