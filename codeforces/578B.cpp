#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxx=2e5+2;
long long arr[maxx];
long long prefix[maxx],suffix[maxx];

int main()
{
    int n,k,x;

    scanf("%d%d%d",&n,&k,&x);
    //long long maxi=100000000ll;

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    // create prefix
    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1] | arr[i];
    }
    // create suffix
    for(int i=n;i>0;i--)
    {
        suffix[i]=suffix[i+1] | arr[i];
    }

    ll multiply=1;
    long long ans=0;
    for(int i=0;i<k;i++)
    {
        multiply*=x;}

        for(int i=1;i<=n;i++)
        {
            ans=max(ans,prefix[i-1] | multiply*arr[i] | suffix[i+1]);
        }
    cout<<ans<<endl;

return 0;

}
