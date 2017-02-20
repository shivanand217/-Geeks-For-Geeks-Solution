// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** we want to multiply a number with any number without using multiplication operator **/

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

int multiply_by_7(int n)
{
    // for multiply by 7
    // n*(8-1)
    n = n<<3 -n; // or n = n<<2 + n<<2 -a or n = n<<2 + n<<1 + n
    return n;
}

int multiply_by_10(int n)
{
    // for multiply by 10
    // n*(8+2)
    n = n<<3 + n<<1; // or n = n<<2 + n<<2 + n<<1
}

int main()
{
int n;
cin>>n;

int mult_7=multiply_by_7(n);
int mult_10=multiply_by_10(n);
cout<<mult_7<<" "<<mult_10<<endl;

return 0;
}

