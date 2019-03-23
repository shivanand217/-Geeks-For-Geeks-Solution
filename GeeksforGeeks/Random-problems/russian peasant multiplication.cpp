// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(log(min(a,b)))
// SPACE COMPLEXITY: O(1) 

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

unsigned int russian_peasant(unsigned int a,unsigned int b)
{
	bool max_a=false,max_b=false;
	if(a>b)max_a=true;else max_b=true;
	int res=0;

	if(max_a)
	{
		while(b>0)
		{
			if(b&1)
			{
				res+=a;
			}
			b=b>>1;
			a=a<<1;
		}
	}
	else
	{
		while(a>0)
		{
			if(a&1)
			{
				res+=b;
			}
			a=a>>1;
			b=b<<1;
		}
	}
	return res;
}


int main()
{
unsigned int a,b;

cin>>a>>b;

unsigned int ans=russian_peasant(a,b);

cout<<ans<<endl;
return 0;

}