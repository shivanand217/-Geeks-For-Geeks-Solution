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

bitset<1000005> f;
int cnt=1;
unordered_map<int,int> un;

void s() {
    cnt=1;
    for(long long i=2; i * i * i < 1000005; i++) {
        long long m = i * i * i;
        for(long long j = m; j < 1000005; j += m) {
            f[j] = 1;
        }
    }
    for(int i=1; i < 1000005;i++){
        if(f[i] == 0){
            un[i] += cnt;
            cnt++;
        }
    }
}

int main() {

    fast;
    s();
    int t,tmp;
    cin>>t;
    for(int i=1; i <= t; i++) {
        cin>>tmp;
        if(un[tmp] > 0) {
            cout<<"Case "<<i<<": "<<un[tmp]<<endl;
        } else {
            cout<<"Case "<<i<<": "<<"Not Cube Free"<<endl;
        }
    }

    return 0;
}

