// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/**
for 7 is little tricky
    two method: first is pick the last digit
    double and subtract that from the rest digit if that is divisible by 7 then yes
    eg: 357 pick 7 make 7*2=14 , do 35-14=21 , 21%7 == 0 hence yes
    method 2: pick last and make a sum of one by one multiplying digit from last with 1,3,2,6,4,5
    eg:2016 , sum = 6*(1) + 1*(3)+ 0*(2)+ 2*(6) = 21%7 ==0 hence yes

    **/

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

bool method1(long long int n)
{
    int p = n%10;
    p*=2;
    n-=p;

    if(n%7==0){

        return true;
    }else{
    return false;
    }
}

bool method2(long long int n)
{
int ar[] = {1,3,2,6,4,5};

int s = sizeof(ar)/sizeof(ar[0]);
long long int tmp = n;

int i=s-1;
int sum =0 ;

int k;

while(tmp > 0)
{
    if(i<0)i=s-1;
    k = tmp % 10;
    sum += k*i;

    i--;
}

if(sum % 7 == 0)
{
    return true;
}
else{
    return false;
}
}

int main()

{
long long int x;
cin>>x;

if(method1(x))
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

if(method2(x))
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

return 0;
}
