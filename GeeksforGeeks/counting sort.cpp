// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(n+range)
// SPACE COMPLEXITY: O(n+k)

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

const int maxn = 1e5+2;
int arr[maxn];int n;

/** we can also modify it to sort a string **/

int main()
{
    read(n)

    int maxx=INT_MIN;
    for(int i=0; i<n; i++)
    {
        read(arr[i])

        if(maxx < arr[i])
            maxx = arr[i];
    }

    // now the range is in between maxx and minn
    int count_[maxx]; // for the count of the array values
    memset(count_,0,sizeof(count_));

    for(int i=0 ;i<n; i++)
    {
        count_[arr[i]]++;
    }

// modify the count array to store sum of previous counts
for(int i=1; i<=maxx; i++)
{
count_[i]+=count_[i-1];
}

// now process the input array again and if value is x then store x at count[x] and decrease the value of count of x so that if further any x meet
// that can be stored at the index previous to this
// following this we get the sorted array

for(int i=0; i<n; i++)
{
    arr[count_[arr[i]]] = arr[i];
    count_[arr[i]]=count_[arr[i]]-1;
}

// print the sorted array
for(int i=0; i<n; i++)
{
    cout<<arr[i]<<" ";
}
    return 0;
}
