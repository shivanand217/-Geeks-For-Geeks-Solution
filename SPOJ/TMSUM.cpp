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

/** easy dp **/

int a[1004];
int MEMO[1004];

int main() {
    fast;
    int t,n;
    cin>>t;

    while(t--) {
        cin>>n;

        for(int i=0; i < n; i++)
            cin>>a[i];
        sort(a,a+n);
        if(n==1) {
            cout<<a[0]<<endl;
            continue;
        }

        if(n==2) {
            cout<<max(a[0] + a[1], a[0] * a[1])<<endl;
            continue;
        }

        MEMO[0] = a[0];
        MEMO[1] = max( a[0]+a[1] , a[0] * a[1]);

        for(int i=2; i<n; i++) {
            MEMO[i]=max(MEMO[i-1] + a[i] , MEMO[i-2] + a[i-1]*a[i]);
        }

        cout<<MEMO[n-1]<<endl;
    }

    return 0;
}

/**
    Recursive solution

    int recur(int index) {
    if(index == 0) {
        return a[index];
    }
    if( index < 0 )
        return 0;
    int ans=0;
    ans = max(recur(index-2)+a[index]*a[index-1] , recur(index-1)+a[index]);
    return ans;

} **/
