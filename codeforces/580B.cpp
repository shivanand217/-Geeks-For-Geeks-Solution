#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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

template<typename T>
void print(T n)
{
    bool neg = 0;
    if(n<0)
    {
        n*=-1;
        neg=true;
    }

    char snum[65];
    int i=0;
    do
    {
        snum[i++]=n%10+'0';
        n/=10;
    }
    while(n);
    --i;

    if(neg)
        putchar('-');
    while(i>=0)
        putchar(snum[i--]);
    putchar('\n');
}

pair<int,int> sm[100005];

int main()
{
    int n,d;
    read_(n);
    read_(d);

    int m,s;

    for(int i=0; i<n; i++)
    {
        read_(m);
        read_(s);
        sm[i] = {m,s};
    }

sort(sm, sm+n);

ll f = sm[0].second;
ll mm = f;

int l=0;

for(int i=1; i<n; i++)
{
    while(sm[i].first - sm[l].first >= d)
    {
        f -= sm[l++].second;
    }

    f += sm[i].second;
    mm = max(f, mm);
}

print(mm);

return 0;
}
