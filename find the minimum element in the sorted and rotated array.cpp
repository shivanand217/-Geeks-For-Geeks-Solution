// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(log(n))
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
using namespace std;

/** the idea is similar to finding pivot in the sorted and rotated array next to the pivot is the minimum **/
/** does not work for duplication **/

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

int n;
int ar[102];

int find_pivot(int lo, int hi)
{
    if(hi < lo) return -1; // no pivot
    if(lo == hi) return lo;

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

int main()
{
    read_(n);
    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }
    int ans = find_pivot(0, n-1);

    if(ans == -1) // array is sorted and not rotated
    {
        cout<<ar[0]<<endl;
    }
    else
    {
        cout<<ar[ans+1]<<endl;
    }
    return 0;
}
