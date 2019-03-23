// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** kadane algorithm to find the maximum subarray problem **/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
using namespace std;

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

int main()
{
    read_(n);
    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }

    int max_so_far=0;
    int max_ending_here=0;
    int l_i=0,r_i=0;

    for(int i=0; i<n; i++)
    {
        max_ending_here += ar[i];
        if(max_ending_here < 0)
        {
            max_ending_here = 0;
            l_i = i+1; r_i = i;
        }
        else
        {

            r_i++;
        }
        if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
    }

    if(l_i == n-1)
    {
        cout<<max_so_far<<endl;
    }
    else
    {
        for(int i=l_i; i<r_i; i++)
        {
            cout<<ar[i]<<" ";
        }cout<<endl;

        cout<<max_so_far<<endl;
    }
    return 0;
}
