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

int gcd(int a,int b){
    if(a==0) {
        return b;
    }
    return gcd(b%a,a);
}

int main() {
    fast;
    int t,x,y,z;
    cin>>t;

    while(t--) {
        cin>>x>>y>>z;
        int g1 = gcd(x,y);
        int g2 = gcd(y,z);
        int g3 = gcd(x,z);
        if(g1 == 1 && g2 == 1 && g3 == 1) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
