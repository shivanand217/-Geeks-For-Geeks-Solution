#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    long long ans = LLONG_MIN,ty1,ty2,temp,cur;
    for(int i=0;i<=n;i++)
	{
        ty1=i;
        cur=n-i;
        ty2=m-2*i;
        if(ty2>=0){
            ty1+=min(ty2,cur/2);
            ans=max(ans, ty1);
        }
	}
	cout<<ans<<endl;
    return 0;
}
