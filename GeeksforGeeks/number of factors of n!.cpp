// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*log(log(n)))

/** by seive we first find all the primes less than n then we calculate the exponent of each prime and multiply those
    to find the number of factors of n!
    Here is an illustration on how the algorithm works
    for finding factors of 16!:

    Prime factors of 16! are: 2,3,5,7,11,13

    Now to the exponent of 2 in 16!
              = [16/2] + [16/4] + [16/8] + [16/16]
              = 8 + 4 + 2 + 1
              = 15

    Similarly,
   exponent of 3 in 16! =  [16/3] + [16/9] = 6
   exponent of 5 in 16! = 3
   exponent of 7 in 16! = 2
   exponent of 11 in 16! = 1
   exponent of 13 in 16! = 1

   So, the no of factors of 16!
         = (15+1) * (6+1) * (3+1) *(2+1)* (1+1) * (1+1)
         = 5376
    **/

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define LL long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

const int maxn = 1e5+2;
int prime[maxn];
vector<int> prime_;

void seive(int n)
{
    memset(prime, 1, sizeof(prime));

    prime[0] = prime[1] = 0;

    for(int i=2; i*i<=maxn ;i ++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=maxn; j+=i)
            {
                prime[j] = 0;
            }
        }
    }

    for(int i=1; i<=maxn; i++)
    {
        if(prime[i])
        {
            prime_.push_back(i);
        }
    }
}

/** or use segmented_seive without extra memory


void segmented_seive(int n)
{

int new_ = (n-2)/2;

int marked[new_];
memset(marked, false, sizeof(marked));


for(int i=1; i<=new_ ;i++)
{

for(int j=i; (i+j+2*i*j)<=new_; j++)
{
marked[i+j+2*i*j] = true;

}

}

prime.push_back(2);

for(int i=1; i<=new_; i++)
{
if(marked[i] == false)
{
prime.push_back(2*i+1);
}

}
}

**/


void calculate_factors(int n)
{
    int k;
    int exp_;
    int tmp,x,p;

    int factors=1;

    for(int i=0; i<prime_.size(); i++)
    {
        exp_ = 0;

        tmp = n;
        x = prime_[i];
        p = prime_[i];

        while((tmp/x) > 0)
        {
            exp_+= tmp/x;
            x*=p;
        }

        factors = factors * (exp_+1);
    }
    cout<<factors<<endl;
}


int main()
{
    int n;
    si(n);

    seive(n);
    //generate_ all primes less than n
    // calculate factors of n!
    calculate_factors(n);
return 0;
}
