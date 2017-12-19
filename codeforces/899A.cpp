#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

int main() {
    fast;
    int n,tmp;
    cin>>n;
    int one=0;
    int two=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp == 1)
            one++;
        else
            two++;
    }

    int ans =0;
    ans += min(one,two);
    one -= ans;
    int p = one/3;
    ans += p;
    cout<<ans<<endl;

    return 0;
}
