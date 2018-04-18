// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O()
// SPACE COMPLEXITY : O()

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

void is_keith_number(lli n)
{
    vector<lli> sequence;
    lli tmp = n;
    string s = "";

    while(tmp > 0)
    {
        s += (tmp % 10 + '0');
        tmp/=10;
    }

    reverse(s.begin(), s.end());


    int sum=0;
    for(int i=0; i<s.length(); i++)
    {
        sequence.push_back(s[i] - '0');
        sum+=s[i] - '0';
    }

bool p = false;

int next = sum;int glob = 0;

    while(1)
    {
        sequence.push_back(next);
        next = 2*next - sequence[glob++];

        if(next > n){    sequence.push_back(next);
 break;}

        if(next == n){    sequence.push_back(next);
p = true;break;} //return true;
    }

    if(p ==  true){

cout<<"it is a keith number"<<endl;
    cout<<"sequence is: "<<endl;
    for(int i=0; i<sequence.size(); i++)
    {
        cout<<sequence[i]<<" ";
    }

    }
    else{
        cout<<"not a keith number"<<endl;
        cout<<"sequence is: "<<endl;
        for(int i=0; i<sequence.size(); i++)
        {
        cout<<sequence[i]<<" ";
        }
    }
    cout<<endl;
   // return true;
}

int main()
{
//clock_t tStart = clock();
lli n;
n = read_lli();

is_keith_number(n);

//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

return 0;

}
