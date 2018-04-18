// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*log(logn))

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

vector<int> prime;

void segmented_seive(int n)
{
    int new_ = (n-2)/2;

    int marked[new_];

    memset(marked, false, sizeof(marked));

    for(int i=1; i<=new_; i++)
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

bool check_palindrome(int n)
{
    string s="";

    while(n > 0)
    {
        s += (n%10 + '0');
        n/=10;
    }

    int i=0, j=s.length()-1;

    while(i < j)
    {
        if(s[i] != s[j])
        {
            return false;
        }

        i++;j--;
    }

return true;
}


int main()
{
    int n;
    si(n);

    segmented_seive(n);

   for(int i=0; i<prime.size(); i++)
   {
       if(check_palindrome(prime[i]))
       {
           cout<<prime[i]<<" ";
       }
   }

   return 0;
}
