// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

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
using namespace std;

int read_int(){
	char r;bool start=false,neg=false;int ret=0;
	while(true){r=getchar();if((r-'0'<0 || r-'0'>9) && r!='-' && !start){continue;}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){	break;	}if(start)ret*=10;start=true;
		if(r=='-')neg=true;else ret+=r-'0';}if(!neg)return ret;else	return -ret;}

lli read_lli(){
 char r;bool start=false,neg=false;lli ret=0;
 while(true){r=getchar();if((r-'0'<0 || r-'0'>9) && r!='-' && !start){	continue;}
 if((r-'0'<0 || r-'0'>9) && r!='-' && start){	break;}if(start)ret*=10;
	start=true;if(r=='-')neg=true;else ret+=r-'0';}if(!neg)	return ret;else	return -ret;}

// first we caluculate the number of prime factors
// in the given range

vector <int> prime;
  // this stores all the primes less than sqrt(n)
// first generate all the primes less than sqrt(n ) using segmented seive

void segmented_seive()
{
    int n = 10000; // sqrt(10^8) = 10000
    int new_ = (n-2)/2;

    int marked[new_+1];
    memset(marked, false, sizeof(marked));

    for(int i=1; i<=new_; i++)
    {
        if(marked[i] == false)
        {
            for(int j=i; (i+j+2*i*j)<=new_; j++)
            {
                marked[i+j+2*i*j] = true;
            }
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

int n_factors(int a,int b,int n)
{
    segmented_seive();
    int result=0;int count_;

    for(int i=a; i<=b; i++)
    {
        count_ = 0;
        int tmp = sqrt(i);
        int c = i;

        for(int j=0; prime[j] <= tmp; j++)
        {
            if(c % prime[j] == 0)
            {
                count_++;
                //remove all the factors of that prime
                while(c % prime[j] == 0)
                {
                    c/=prime[j];
                }
            }
        }

        //check if still c is greater than 1 then c is prime
        if(c !=1)
        {
            count_++;
        }

        if(count_ == n)
        {
            result++;
        }
    }
    return result;
}

int main(){

int a,b,n;

a = read_int();
b = read_int();
n = read_int();

int ans = n_factors(a,b,n);

cout<<ans<<endl;

return 0;

}
