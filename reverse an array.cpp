// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(log(n))
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
using namespace std;

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

void swap_(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void reverse_array()
{
    int l=0;
    int r=n-1;

    while(l < r)
    {
        swap_(&ar[l],&ar[r]);
        l++;r--;
    }

    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }cout<<endl;
}

int main()
{
    read_(n);
    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }
    reverse_array();

    return 0;
}
