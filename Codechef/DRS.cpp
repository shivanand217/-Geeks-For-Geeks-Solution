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
    int t,n,d1,d2,prev,total,O,B,review;
    string s;
    double k;
    cin>>t;
    int tot;
    while(t--) {
        total=0;
        cin>>n;
        O=0;
        B=0,review=2;
        for(int i=0; i <n; i++) {
            cin>>s;
            O=0;
            B=0;
            int j=0;
            while(s[j] != '.') {
                O = O*10 + (s[j]-'0');
                j++;
            }
            if(s[j] == '.')
                j++;
            B = s[j]-'0';
            if(i==0) {
                review--;
                total++;
                prev=O;
                continue;
            }
            d1 = prev/80;
            d2 = O/80;
            if(d1 < d2) {
                review=1;
                total++;
            } else if(d1 == d2) {
                if(review > 0) {
                    review--;
                    total++;
                }
            }
            prev = O;
        }
        cout<<total<<endl;
    }

    return 0;
}
