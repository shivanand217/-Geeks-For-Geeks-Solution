// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(10^n)

/** we are using a simple recursion technique
    we just store digits from 0 to 9 at the first
    index then we recurse for all the index and check
    that if requirement is satisfied **/

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

void sumNdigit_num(int n, int sum, char *out,int index)
{
    // base case
    if(index > n || sum < 0)
        return;

    if(index == n)
    {
        if(sum == 0)
        {
            out[index] = '\0';
            cout<<out<<" ";
        }
        return;
    }

    for(int i=0; i<=9; i++)
    {
        out[index] = i+'0';
        sumNdigit_num(n, sum-i, out, index+1);
    }
}

void solve(int n, int sum)
{
    char out[n+1]; // we allocate for the n length digit

    //one by one fill digits at the first position and recurse for the th
    //second position

    for(int i=1; i<=9; i++)
    {
        out[0] = i+'0';
        sumNdigit_num(n, sum-i, out, 1);
    }
}

int main()
{
    int n;
    n = read_int();

    int sum;
    sum = read_int();

    solve(n, sum);

    return 0;
}
