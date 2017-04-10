// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(n)

/** Recurrence for Even Fibonacci sequence is:
     EFn = 4EFn-1 + EFn-2
     with seed values
     EF0 = 0 and EF1 = 2.

derivation below:

Fn = Fn-1 + Fn-2 [Expanding both terms]
   = Fn-2 + Fn-3 + Fn-3 + Fn-4
   = Fn-2 + 2Fn-3 + Fn-4 [Expending first term]
   = Fn-3 + Fn-4 + 2Fn-3 + Fn-4
   = 3Fn-3 + 2Fn-4  [Expending one Fn-4]
   = 3Fn-3 + Fn-4 + Fn-5 + Fn-6 [Combing Fn-4 and Fn-5]
   = 4Fn-3 + Fn-6

Since every third Fibonacci Number is even, So if Fn is
even then Fn-3 is even and Fn-6 is also even. Let Fn be
xth even element and mark it as EFx.
If Fn is EFx, then Fn-3 is previous even number i.e. EFx-1
and Fn-6 is previous of EFx-1 i.e. EFx-2
So
Fn = 4Fn-3 + Fn-6
which means,
EFx = 4EFx-1 + EFx-2 **/


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

LL int nth_even_fibo(int n)
{
    LL int fibo[maxn];

    fibo[0] = 0;
    fibo[1] = 2;

    LL int tmp=2;

    int k=2;

    while(1)
    {
        fibo[tmp] = (4 * fibo[tmp-1] + fibo[tmp-2]);

        if(k == n)
        {
            return fibo[tmp];
        }

        tmp++;k++;
    }
}

int main()
{

//clock_t tStart = clock();
int n;
n = read_int();

LL int value = nth_even_fibo(n);

cout<<value<<endl;
//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
return 0;
}
