// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*log(n))
// SPACE COMPLEXITY : O(maxn)

/** it works as first we calculate p = (n-2)/2 a new number
    then we marked all the numbers of the form i+j+2*i*j in a for loop
    then for all the unmarked number x we found that 2*x+1 is a prime
    one advantage of seive of sundaram is it consumes less memory than seive of erathosenes
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

vector<int> prime;

void seive_of_sundaram(int n)
{
int new_ = (n-2)/2;

int marked = new int[new_+1];
memset(marked, false, sizeof(marked));

for(int i=1; i<=new_; i++)
{
    for(int j=i; (i+j+2*i*j) <= n; j++)
    {
        marked [i+j+2*i*j] = true;
    }
}
// now for all the unmarked 2*x+1 will give us a prime

prime.push_back(2);

for(int i=1; i<= new_; i++)
{
    if(marked[i] == false)
    prime.push_back(2*i+1);
}

}

int main()
{
int n;
read(n)

seive_of_sundaram(n);

for(int i=0; i<prime.size(); i++)
{
    cout<<prime[i]<<" ";
}

return 0;
}
