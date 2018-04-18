// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** problem statement
    Given a number N which may be 10^5 digits long,
    the task is to count all the digits in N which divide N.
    Divisibility by 0 is not allowed.
    If any digit in N which is repeated divides N,
    then all repetitions of that digit should be counted
    i.e., N = 122324, here 2 divides N and it appears 3 times.
    So count for digit 2 will be 3.
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

bool check_3(string s){int cnt=0;for(int i=0; i<s.length(); i++){cnt+=s[i]-'0';}return (cnt%3 == 0);}
bool check_4(string s){int p=(s[s.length()-2]-'0')*10 + (s[s.length()-1]-'0'); return (p%4 == 0);}
bool check_5(string s){return (s[s.length()-1] == '0' || s[s.length()-1] == '5');}
bool check_6(string s){if(check_3(s)){if((s[s.length()-1]-'0')%2 == 0)return true;else return false;} return false;}
bool check_7(string s){int a[6]={1,3,2,6,4,5}; int sum=0;int p=0;for(int i=s.length()-1; i>=0; i--){if(p>5)p=0;sum+=a[p]*(s[i]-'0');p++;}return (sum%7==0);}
bool check_8(string s){int p = (s[s.length()-3]-'0')*100 + (s[s.length()-2]-'0')*10 + (s[s.length()-1]-'0'); if(p % 8 == 0)return true; else return false;}
bool check_9(string s){if(check_3(s))return true;else return false;}

int solve(string s)
{
    map<int,int> ma;

    int k;

    for(int i=0; i<s.length(); i++)
    {
        k = s[i]-'0';
        if(k == 1)ma[k]++;
        if(k==2)
        {
            if((s[s.length()-1] - '0')%2 == 0)
            {
                ma[k]++;
            }
        }
        else if(k==3)
        {
            if(check_3(s))
            {
                ma[k]++;
            }
        }
        else if(k==4)
        {
            if(check_4(s))
            {
                ma[k]++;
            }
        }
        else if(k==5)
        {
            if(check_5(s))
            {
                ma[k]++;
            }
        }
        else if(k==6)
        {
            if(check_6(s))
            {
                ma[k]++;
            }
        }
        else if(k==7)
        {
            if(check_7(s))
            {
                ma[k]++;
            }
        }
        else if(k==8)
        {
            if(check_8(s))
            {
                ma[k]++;
            }
        }
        else if(k==9)
        {
            if(check_9(s))
            {
                ma[k]++;
            }
        }
    }
    int ans=0;

    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        ans += ma[it->first];
    }

    return ans;
}

int main()
{
//clock_t tStart = clock();
string s;
cin>>s;

int ans = solve(s);
cout<<ans<<endl;

//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
return 0;
}
