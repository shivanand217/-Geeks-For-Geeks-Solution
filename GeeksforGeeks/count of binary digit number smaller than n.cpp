// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

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

/** by naive approach we can iterate over all the elements upto n and check if it is binary or not complexity is O(n)
    we can do a bfs starting from 1 with t as 1 every time push t*10 and t*10+1 in the queue and check if popped element crossed n
    then stop **/

LL pow(LL a, LL b) {
    LL x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

LL gcd_(LL a,LL b)
{
    if(b==0)
        return a;
    return (b,a%b);
}

LL lcm_(LL a,LL b)
{
    LL lcm_value=((a*b)%mod)/(gcd_(a,b));
}

int main()
{
    int n;
    cin>>n;

    queue<int> qu;

    qu.push(1);

    int count_num=1;int num;
    while(!qu.empty())
    {
        num = qu.front();
        qu.pop();

        if(num > n)break;

        count_num++;

        qu.push(num*10);qu.push(num*10+1);
    }

    cout<<count_num<<endl;
    return 0;
}
