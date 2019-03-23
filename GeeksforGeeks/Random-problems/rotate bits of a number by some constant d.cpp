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
#define ret return 0;
#define ll long long
#define max_bits 32
using namespace std;

int leftRotate(int n,unsigned int d)
{
return ((n<<d)|(n>>(max_bits-d));
}

int rightRotate(int n,unsigned int d)
{
return ((n>>d)|(n<<(max_bits-d)));
}

int main()
{

int n;int d;
cin>>n>>d;

//left rotate
cout<<leftRotate(n,d)<<endl;

//right rotate
cout<<rightRotate(n,d)<<endl;

return 0;
}
