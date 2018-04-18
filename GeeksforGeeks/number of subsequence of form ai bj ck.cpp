// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)

/** Given a string, count number of subsequences of the form ai^bj^ck, where i >= 1, j >=1 and k >= 1. **/

/**

Input  : abbc
Output : 3
Subsequences are abc, abc and abbc

Input  : abcabc
Output : 7
Subsequences are abc, abc, abbc, aabc
abcc, abc and abc

**/

#include<bits/stdc++.h>
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

// s contains only a,b,c
int count_subsequence(string s)
{
    int acount=0,bcount=0,ccount=0;
    for(unsigned int i=0; i<s.size(); i++)
    {
        if(s[i] == 'a')
        {
            acount = (1+ 2*acount);
        }
        else if(s[i] == 'b')
        {
            bcount = (acount + 2*bcount);
        }
        else if(s[i] == 'c')
        {
            ccount = (bcount + 2*ccount);
        }
    }
return ccount;
}

int main()
{
    string s = "abbc";
    int ans = count_subsequence(s);
    cout<<ans<<endl;
    return 0;
}
