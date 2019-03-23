// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*(2^n))
// SPACE COMPLEXITY : O(2^n)

/** problem is to find all the subset of an array
    Power Set Power set P(S) of a set S is the set of all subsets of S. For example S = {a, b, c}
    then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.
    If S has n elements in it then P(s) will have 2^n elements

algorithm:
Input: Set[], set_size
1. Get the size of power set
    powet_set_size = pow(2, set_size)
2  Loop for counter from 0 to pow_set_size
     (a) Loop for i = 0 to set_size
          (i) If ith bit in counter is set
               Print ith element from set for this subset
     (b) Print seperator for subsets i.e., newline

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

/*
inline int mult(int a , int b) { lli x = a; x *= lli(b); if(x >= mod) x %= mod; return x; }
inline int add(int a , int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a , int b) { return a - b < 0 ? mod - b + a : a - b; }
*/

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

/* comb* ncr*/
/*
lli  comb[1001][1001];
lli combination()
  {for(int i = 0; i < 1000; i++) {comb[i][0] = 1;for(int j = 1; j <= i; j++)comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;}}
*/
/* prime factor of all numbers from 1 to till n */;
/*bool  factu[10000010];vector<int> fact[10000010];
int  factor(int  n)
 {fact[1].push_back(1);for(int i=2;i<=n;i++){ if(!factu[i]){for(int j=i;j<=n;j+=i){factu[j]=1;fact[j].push_back(i);}}}}
*/

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

const int maxn = 1e3+2;
int ar[maxn];

int main()
{
    clock_t tStart = clock();

int n;// set size
n = read_int();

for(int i=0; i<n; i++)
{
    si(ar[i]);
}

int power_set_size = fast_pow(2, n);
int tmp,l;

bool m;

map<int,vector<int> > power_set;

for(int i=0; i<power_set_size; i++)
{
    for(int j=0; j<n; j++)
    {
        m = false;
        tmp = i;
        // check if jth bit in i is set or not
        l=0;
        while(tmp > 0)
        {
            if((tmp & 1))
            {
             if(l>j)break;
             else
             {
                 if(l==j)
                 {
                     m = true;break;
                 }
             }
            }
            l++;
            tmp>>=1;
        }

        if(m == true)
            power_set[i].push_back(ar[j]);
    }
}

for(auto it = power_set.begin(); it!=power_set.end(); it++)
{
    for(int i=0; i<power_set[it->first].size(); i++)
    {
        cout<<power_set[it->first][i]<<" ";

    }
    cout<<endl;
}

//+1 for an empty set
cout<<endl;

printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
return 0;

}
