// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n) // in preprocessing
// SPACE COMPLEXITY : O(n)

/** in this method we do some preprocessing we obtain the numbers as
    if we got the remainder by the first number divided by a
    we preprocess for every number one by one by the formula
    rem[i] = (rem[i-1]%a) + (str[i]-'0')%a
    similarly we do for the right side
    **/

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define LL long long
#define mod 1000000007
using namespace std;

int fast_pow(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a,int b)
{
    int ans;
    ans = (a*b)/gcd(a,b);
    return ans;
}

int main()
{

string s;
cin>>s;

int a,b;
cin>>a>>b;

int *rem_left = (int *)malloc((s.length()-1)*(sizeof(int)));
int *rem_right = (int *)malloc((s.length()-1)*(sizeof(int)));

int f = 1;

rem_left[0] = (s[0]-'0')%a;
rem_right[s.length()-1] = (s[s.length()-1] - '0')%b;

// preprocess for left part
for(int i=1; i<s.length()-1; i++)
{
    rem_left[i] = (rem_left[i-1]*10)%a + (s[i]-'0')%a;
}

// similarly preprocess for right part
for(int i=s.length()-2; i>=1; i--)
{
    rem_right[i] = (rem_right[i+1]%b + ((s[i]-'0')*fast_pow(10,f))%b) %b;
    f++;
}

for(int i=0; i<s.length()-1; i++)
{
    if(rem_left[i] == 0)
    {
        if(rem_right[i+1] == 0)
        {
            for(int k=0; k<=i; k++)
            {
                cout<<s[k];
            }cout<<" ";

            for(int k=i+1; k<s.length(); k++)
            {
                cout<<s[k];
            }cout<<" ";
            return 0;
        }
    }
}

// else not found the paartition
cout<<"not possible"<<endl;

return 0;
}
