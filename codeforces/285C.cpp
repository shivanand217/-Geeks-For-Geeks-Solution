#include<bits/stdc++.h>
using namespace std;
long long a[300005];
int main()
{
    long long n;
    cin>>n;
    //a[0]=LLONG_MIN;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long ans=0;
    for(long long i=0;i<n;i++){
        ans += abs((i+1)-a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
