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

void f(long long n, vector<long long> &div) {
    long long tmp = n;
    for(long long i=2; i*i < tmp; i++) {
        if(n % i == 0) {
            if(i == n / i) {
                div.pb(i);
            } else {
                div.pb(i);
                div.pb(n/i);
            }
        }
        if(n == 0)
            break;
    }
}

bool overlucky(long long k) {
    bool f=false, s=false;
    while(k > 0) {
        int p = k%10;
        if(p == 4)
            f=true;
        if(p == 7)
            s=true;
        if(f==true || s==true)
            break;
        k /= 10;
    }
    if(f==true || s == true){
        return true;
    }
    return false;
}

int main() {
    fast;
    int t;
    cin>>t;
    long long n,k;
    int cnt;

    while(t--) {
        cnt=0;
        cin>>n;
        //div.pb(n);
        for(long long d=1; d*d <= n; d++){
             if (n % d == 0) {
                cnt += overlucky(d);
                if (d * d < n) {
                    cnt += overlucky(n / d);
                }
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
