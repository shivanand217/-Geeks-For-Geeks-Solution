// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(logn) //modify the binary search
// SPACE COMPLEXITY: O(1)

/**
Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions,
i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array.
Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1]. **/

/** we compare for the three elements if the key is found **/

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
int arr[maxn];

int n,key;
int mid;

void solve(int val)
{
    int low=0;int high=n-1;

    while(low <= high)
    {
        mid = low+(high-low)/2;

        if(arr[mid] == value)
        {
            return mid;
        }
        if(arr[mid] - 1 <)
    }
}

int main()
{
   read(n)

   rr(n)
   {
       read(arr[i])
   }
   read(key)

   solve(key);
ret
}
