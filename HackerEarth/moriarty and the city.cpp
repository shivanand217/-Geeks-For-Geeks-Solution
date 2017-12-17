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
    ll n;
    cin>>n;
    int tmp;
    string s="";
    for(ll i=0;i<n;i++){
        cin>>tmp;
        s += (tmp+'0');
    }
    ll ans=0LL;
    ll i=0;
    ll ans1=0LL;
    while(i < s.length()-1) {
           if(s[i] == s[i+1]) {
                ans1++;
                while(s[i] == s[i+1]) {
                    ans1++;
                    i++;
                }
                i++;
                ans =  max(ans1,ans);
                ans1 = 0LL;
           } else {
                i++;
           }
    }
    cout<<ans<<endl;

    return 0;
}
