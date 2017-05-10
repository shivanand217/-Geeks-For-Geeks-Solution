// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** Majority Element:
    A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).
    algorithm:

    The algorithm for first phase that works in O(n) is known as Moore’s Voting Algorithm. Basic idea of the algorithm is
    if we cancel out each occurrence of an element e with all the other elements
        that are different from e then e will exist till end if it is a majority element.

    **/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
using namespace std;

const int maxn = 1e5+2;
int ar[maxn];
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
 else
    x += r-'0';
 }

 if(neg)
    x*=-1;

}

int solve()
{
    int m_i=0;
    int c=1;
    for(int i=1; i<n; i++)
    {
        if(ar[m_i] == ar[i])
        {
            c++;
        }
        else
        {
            c--;
        }
        if(c == 0)
        {
            m_i=i;
            c=1;
        }
    }
    // after doing check if this is that element
    c=0;
    for(int i=0; i<n; i++)
    {
        if(ar[m_i] == ar[i])
        {
            c++;
        }
    }

    if(c>n/2)
    {
        cout<<ar[m_i]<<endl;
    }
    else
    {
        cout<<"no majority element"<<endl;
    }
}

int main()
{
    read_(n);
    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }
    solve();
    return 0;
}
