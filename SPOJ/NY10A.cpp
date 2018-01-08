#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define se second
#define fi first

#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

int main() {
    fast;
    int n,tmp;
    cin>>n;
    string s,t;
    int cnt[9];
    for(int i = 1; i <= n; i++) {
        memset(cnt, 0, sizeof(cnt));
        cin>>tmp;
        cin>>s;
        for( int j=0; j < s.length()-2; j++ ) {
            t = s.substr(j, 3);
            if(t == "TTT")
                cnt[1]++;
            else if(t == "TTH")
                cnt[2]++;
            else if(t == "THT")
                cnt[3]++;
            else if(t == "THH")
                cnt[4]++;
            else if(t == "HTT")
                cnt[5]++;
            else if(t == "HTH")
                cnt[6]++;
            else if(t == "HHT")
                cnt[7]++;
            else if(t == "HHH")
                cnt[8]++;
        }
        cout<<tmp<<" ";
        for(int k=1; k<=8; k++)
            cout<<cnt[k]<<" ";
        cout<<endl;
    }

    return 0;
}
