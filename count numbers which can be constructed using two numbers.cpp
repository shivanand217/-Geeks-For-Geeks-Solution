// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(n)

/** Given three positive integers x, y and n,
    the task is to find count of all numbers from 1 to n that can be formed using x and y.
    A number can be formed using x and y if we can get it by adding any number of occurrences of x and/or y
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

int solve(int n, int x,int y,vector<int> &ans)
{
    int p1,p2;

    for(int i=2; i<=n; i++)
    {
        if((i % x) == 0 || (i % y) == 0)
        {
            if(i % x == 0)
            {
                ans.push_back(i);
            }
            else
            {
                ans.push_back(i);
            }
        }
        else{

        int a1 = i - x;int a2 = i- y;
        if(a1 % y == 0 || a2 %x == 0)
        {
            ans.push_back(i);
        }
        else{
        p1 = i % max(x,y);p2 = i % min(x,y);

        if(p1 == min(x,y))
        {
                ans.push_back(i);
        }
        else{
        if(p2 == max(x,y))
        {
            ans.push_back(i);
        }

        }
        }

        }
    }
}

int main()
{
//clock_t tStart = clock();
int n,x,y;

n = read_int();
    x = read_int();
        y = read_int();

vector<int> ans;

solve(n,x,y, ans);

for(int i=0; i<ans.size(); i++)
{
    cout<<ans[i]<<" ";
}cout<<endl;

//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
return 0;

}
