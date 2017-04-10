// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME: O(n*log(log(n)))

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

/** comb* ncr
lli  comb[1001][1001];
lli combination()
  {for(int i = 0; i < 1000; i++) {comb[i][0] = 1;for(int j = 1; j <= i; j++)comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;}}
**/

/** prime factor of all numbers from 1 to till n
bool  factu[10000010];vector<int> fact[10000010];
int  factor(int  n)
 {fact[1].push_back(1);for(int i=2;i<=n;i++){ if(!factu[i]){for(int j=i;j<=n;j+=i){factu[j]=1;fact[j].push_back(i);}}}}
**/

/**
map<int,vector<int> > power_set_of_array(int n)// n is the size of array
{
int power_set_size = fast_pow(2, n);int tmp,l;bool m;map<int,vector<int> > power_set;
for(int i=0; i<power_set_size; i++)
{for(int j=0; j<n; j++){m = false;tmp = i;l=0;while(tmp > 0){if((tmp & 1)){if(l>j)break;else{if(l==j){m = true;break;}}}l++;tmp>>=1;}if(m == true)
            power_set[i].push_back(ar[j]);}}
return power_set;
}
**/

using namespace std;

LL fast_pow(LL x,LL n)
{
    LL result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}

LL gcd(LL a,LL b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

LL lcm(LL a,LL b)
{
    int ans;
    ans = (a*b)/gcd(a,b);
    return ans;
}

const int maxn = 1e4+2;
int arr[maxn];
bool isComposite[maxn];

LL int lcm_=1;

void lcm_of_array(int n)
{
    for(int i=0; i<n; i++)
    {
        lcm_ = lcm(lcm_, arr[i]);
    }
}

void generate_prime(vector<int > &prime)
{

memset(isComposite, false, sizeof(isComposite));
isComposite[0] = isComposite[1] = true;
for(int i=2; i*i<=maxn; i++)
{
    if(isComposite[i])
    {
        for(int j=i*2; j<=maxn; j+=i)
        {
            isComposite[j] = true;
        }
    }
}
for(int i=1; i<=maxn; i++)
{
    if(!isComposite[i])
    {
        prime.push_back(i);
    }
}
}

void find_prime_factors(int n, vector<int > &prime_factors, vector<int> prime)
{
    for(int i=0; i<prime.size(); i++)
    {
        if(lcm_ < 2 || lcm_ < prime[i])
        {
            break;
        }

        if(lcm_ % prime[i] == 0)
        {
            while(lcm_ % prime[i] == 0)
            {
                lcm_ = lcm_/prime[i];
            }
            prime_factors.push_back(prime[i]);
        }
    }
}

int main()
{
//clock_t tStart = clock();
int n;
n = read_int();

for(int i=0; i<n; i++)
{
    si(arr[i]);
}
lcm_of_array(n);

vector<int > prime_factors;
vector<int > prime;

generate_prime(prime);
find_prime_factors(n, prime_factors, prime);

for(int i=0; i<prime_factors.size(); i++)
{
    cout<<prime_factors[i]<<" ";
}

//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
return 0;
}
