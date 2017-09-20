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

int n,k;
long long int m[100005];

int main()
{
    read_(n);
    read_(k);

    long long int max_ = -1000000000LL;
    for(int i=1; i<=n; i++)
    {
        read_(m[i]);
    }

    if(n == 1)
    {
        cout<<m[1]<<endl;
        return 0;
    }

    if(k >= n)
    {
        for(int i=1; i<=n; i++)
        {
            max_ = max(m[i], max_);
        }
        cout<<max_<<endl;return 0;
    }

    int p = n;

    while((p) !=  (2*k))
    {
        if(m[p] > max_)
        {
            max_ = m[p];
        }
        p--;
        k--;
    }

    int i=1;
    while(i < p)
    {
        if(m[p] + m[i] > max_)
        {
            max_ = m[p] + m[i];
        }
        i++;
        p--;

    }


    cout<<max_<<endl;
    return 0;
}
