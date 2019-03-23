// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O()
// SPACE COMPLEXITY : O()

/** A Seed of a number n is a number x such that multiplication of x with its digits is equal to n.
The task is to find all seeds of a given number n. If no seed exists,
then print the same. **/

/** we can get this by looping upto n/2 and id i divides n evenly then get the product of digit and check **/

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

bool get_product_of_digit(int x,int n)
{
    int tmp;
    int tp2=x;
    int i=0;

    long long prod=1;

    while(tp2)
    {

    tmp = tp2%10;
    prod*=tmp;
    tp2/=10;

    }

    prod*=x;

    return (prod == n);
}

int main()
{
    vector<pair<int,int> > v;
    int n;
    read(n)

    for(int i=1; i<=n/2; i++)
    {
        if(n%i == 0 && get_product_of_digit(i,n))
        v.push_back({i,n});
    }

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].first<<"->"<<v[i].second<<endl;
    }

    return 0;
}
