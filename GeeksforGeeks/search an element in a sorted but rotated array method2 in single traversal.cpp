// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(log(n))
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
using namespace std;

/**
    the idea of this method is we take lo and high
    if mid is lesser than the lo element then right subarray from mid is sorted
    if mid is greater than lo then left subarray from mid will contain the
    check in those range with binary search
    else recursively go to the other part
**/

int ar[102];
int n;

template<typename T>
void read_(T &x)
{
 char r;
 int start=0,neg=0;
 x=0;

 while(1)
{
 r=getchar();
 if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
    {continue;}
 if((r-'0'<0 || r-'0'>9) && r!='-' && start)
    {break;}

 if(start)
    x*=10;

  start=1;

 if(r=='-')
    neg=1;
 else x += r-'0';
 }

 if(neg)
    x*=-1;
}

int binary_search_(int lo, int hi, int key)
{
    if(hi < lo)
    {
        return -1;
    }
    int mid = lo + (hi-lo)/2;

    if(ar[mid] == key)
    {
        return mid;
    }
    else if(ar[mid] > key)
    {
        return binary_search_(lo, mid-1, key);
    }
    else
    {
        return binary_search_(mid+1, hi, key);
    }
}

int find_answer(int lo,int hi,int key)
{
    int mid = lo + (hi-lo)/2;
    if(lo+1 == hi)
    {
        if(ar[lo] == key)
        {
            return lo;
        }
        if(ar[hi] == key)
        {
            return hi;
        }
        return -1;
    }

    if(ar[mid] == key)
    {
        return mid;
    }
    else  if(ar[mid] >= ar[lo]) // left subarray from mid is sorted
    {
        if(key >= ar[lo] && key <= ar[mid])
        {
            return binary_search_(lo, mid, key);
        }
        else
        {
            return find_answer(mid+1, hi, key);
        }
    }
    else
    {
        if(key >= ar[mid] && key <= ar[hi])
        {
            return binary_search_(mid, hi, key);
        }
        else
        {
            return find_answer(lo, mid-1,key);
        }
    }
}

int main()
{
    read_(n);

    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }

    int ans = find_answer(0, n-1, 1);
    cout<<ans<<endl;

    return 0;
}
