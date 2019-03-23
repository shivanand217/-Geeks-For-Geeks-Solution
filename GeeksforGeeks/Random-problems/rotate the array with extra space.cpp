// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(n)

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

void rotate_(int d)
{
    int *tmp = new int[n];

    int i= d;
    int j=0;

    while(i<n)
    {
        tmp[j++] = ar[i++];
    }

    for(i=0; i<d; i++)
    {
        tmp[j++] = ar[i];
    }

    for(int i=0; i<n; i++)
    {
        cout<<tmp[i]<<" ";
    }cout<<endl;
}

int main()
{
    read_(n);
    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }

    int d;
    read_(d);

    rotate_(d);

    return 0;
}
