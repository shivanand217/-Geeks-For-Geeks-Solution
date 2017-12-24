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

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(d*2 < c || c*2 < d || d >= b) {
        cout<<"-1"<<endl;
        return 0;
    }

    cout<<a*2<<" "<<b*2<<" "<<min(2*c,2*d)<<endl;

    return 0;
}
