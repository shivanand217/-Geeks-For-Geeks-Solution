// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

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
read(a)read(b)

// we have to divode the string into two parts such that first part is divisible by a and second part is divisible by b
int i=0;int j;

int num1=s[0]-'0';
int num2=0;

int fac = 0;
// first calculate the second number
j=s.length()-1;

int curr;

while(j>=1)
{
    num2 += (s[j]-'0')*fast_pow(10,fac);
    fac++ ; j--;
}

j=1;

fac = s.length()-2;

while(1)
{

if(num1 % a == 0 && num2 % b == 0)
{
 // we got our answer
 cout<<num1<<" "<<num2<<endl;
return 0;//break;
}

curr = fast_pow(10,fac);
i++;
j++;

fac--;

if(j>s.length()-1)
{
    break;
}
//recalculate first and second number
num2 -= (s[j-1]-'0')*curr;

// calculate num1
int f = 0;num1=0;
for(int k=i; k>=0; k--)
{
    num1+= (s[k]-'0')*fast_pow(10,f);
    f++;
}

}
cout<<"no any partition found"<<endl;

return 0;
}

