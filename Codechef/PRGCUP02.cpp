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
int gcd(int a,int b) {
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}
int main() {
    fast;
    int t,a[3],x,y,z;
    cin>>t;
    while(t--) {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        x=a[0];
        y=a[1];
        z=a[2];
        bool ans=false;
        if(x+y > z && y+z > x && x+z > y){
            ans=true;
        }
        if(ans==false){
            cout<<"NO"<<endl;
            continue;
        }
        int cop;
        cop = gcd(x,gcd(y,z));
        ans=true;
        if(z*z != y*y + x*x) {
            ans = false;
        }
        if(ans == false){
            cout<<"NO"<<endl;
            continue;
        }
        if(cop==1){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
