// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n) // for precomputation
// SPACE COMPLEXITY : O(n)

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


int read_int(){
	char r;bool start=false,neg=false;int ret=0;
	while(true){r=getchar();if((r-'0'<0 || r-'0'>9) && r!='-' && !start){continue;}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){	break;	}if(start)ret*=10;start=true;
		if(r=='-')neg=true;else ret+=r-'0';}if(!neg)return ret;else	return -ret;}

const int maxn = 1e5+2;//max length of string
int sum[maxn];

void precompute(string s)
{

sum[0] = s[0]-'0';

for(int i=1; i<s.length(); i++)
{
    sum[1] = sum[0]+(s[i]-'0');
}

}

int main()
{
    string s;
    cin>>s;
    precompute(s);

    int q;
    si(q); // number of queries

    int l,r;
    int diff;

    for(int i=0; i<q; i++)
    {
        si(l);si(r);
        if(l>0)
        diff = sum[r]-sum[l-1];
        else
            diff = sum[r];


    if(diff % 3 == 0)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }

    }


    return 0;
}
