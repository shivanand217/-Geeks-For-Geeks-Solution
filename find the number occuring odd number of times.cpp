// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O()
// SPACE COMPLEXITY : O()

/** best solution is we are taking XOR of all the elements then the remained xor will be the element which is occuring odd number of times **/

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

    int xor_=0;

    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }

    for(int i=0; i<n; i++)
    {
        xor_ ^= ar[i];
    }

    cout<<xor_<<endl;

    return 0;
}
