// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(logn)
// SPACE COMPLEXITY : O(1)

/** in this method i am just finding the pivot and after then doing binary search **/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
using namespace std;

int ar[102];
int n;

/** we are considering all element are distinct **/
/** pivot is an element for which the next element is smaller in the array **/

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

int binary_search_(int lo,int hi,int key)
{
    if(hi < lo) return -1;
    int mid = lo + (hi-lo)/2;

    if(ar[mid] == key)
    {
        return mid;
    }
    if(ar[mid] > key)
    {
        return binary_search_(lo, mid-1,key);
    }
    else
    {
        return binary_search_(mid+1,hi,key);
    }
}

int find_pivot(int lo, int hi)
{
    if(hi < lo) return -1; // no pivot

    if(lo == hi)return lo;

    int mid = lo + (hi-lo)/2;

    if(mid < hi && ar[mid+1] < ar[mid])
    {
        return mid;
    }
    if(mid > lo && ar[mid-1] > ar[mid])
    {
        return mid-1;
    }
    if(ar[lo] >= ar[mid])
    {
        return find_pivot(lo, mid-1);
    }
    else
    {
        return find_pivot(mid+1,hi);
    }
}

int find_answer(int key)
{
    int pivot = find_pivot(0, n-1);
    if(pivot == -1) // sorted not rotated
    {
        return binary_search_(0,n-1,key);
    }

    cout<<pivot<<endl;

    if(ar[pivot] == key)
    {
        return pivot;
    }
    if(ar[0] <= key)
    {
        return binary_search_(0,pivot,key);
    }
    else
    {
        return binary_search_(pivot+1,n-1,key);
    }
}


int main()
{
    read_(n);
    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }

    int ans = find_answer(2);
    if(ans == -1)
    {
        cout<<"key is not present"<<endl;
    }
    else
    cout<<ans<<endl;
    return 0;
}
