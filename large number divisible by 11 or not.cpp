// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** idea is if difference between sum of digits at even places and odd places if divisible by 11 then yes otherwise no **/

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define LL long long
#define mod 1000000007
using namespace std;

int main(){

string s;
cin>>s;

int sum_even = 0;
int sum_odd = 0;

for(int i=0; i<s.length(); i+=2)
{
    sum_even += (s[i] - '0');
}

for(int i=1; i<s.length(); i+=2)
{
    sum_odd +=(s[i] - '0');
}

int diff =abs(sum_odd - sum_even);

if(diff % 11 == 0)
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

return 0;
}
