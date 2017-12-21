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

    std::ios::sync_with_stdio(false);
    ll t,n,f,s;
    string name;
    map< pair<ll,ll>,string>  un;
    cin>>n;

    pair<ll,ll> p;
    for(ll i=0; i<n; i++) {
        cin>>f>>s;
        cin>>name;
        p = make_pair(f,s);
        un[p] = name;
    }

    cin>>t;
    while(t--) {
        cin>>f>>s;
        p = make_pair(f,s);
        cout<<un[p]<<endl;
    }

    return 0;
}


