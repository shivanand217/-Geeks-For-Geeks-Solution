// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** goldbach conjecture says that every even integer greater than 2 can be expressed sum of two primes
    we generate all the primes less than n for a given n
    one by one we subtract for each prime and check if the difference is also a prime
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

int a,b;

void seive_of_sundaram(int n)
{
    int n_new = (n-2)/2;

    int *marked = (int *)malloc((n_new+1)*(sizeof(int)));

    memset(marked, false, sizeof(marked));

    // mark all of form i+j+2*i*j as true
    for(int i=1; i<=n_new; i++)
    {
        for(int j=i; (i+j+2*i*j)<= n_new; j++)
        {
            marked[i+j+2*i*j] = true;
        }
    }

    // for all unmarked x 2*x+1 will give the prime

    prime.push_back(2);

    for(int i=1; i<=n_new; i++)
    {
        if(!marked[i])
        {
            prime.push_back(2*i+1);
        }
    }


}


int main()
{
int n;
read(n)

if(n % 2 != 0 || n==2)
{
    cout<<"not possible";
}
else
{
    seive_of_sundaram(n);

    int diff;

    for(int i=2; i<=n; i++)
    {
        if(binary_search(prime.begin(), prime.end(), i))
        {
            diff = n - i;

            if(binary_search(prime.begin(), prime.end(), diff))
            {
                cout<<i<<" "<<diff<<endl;break;
            }
        }
    }

}

return 0;
}
