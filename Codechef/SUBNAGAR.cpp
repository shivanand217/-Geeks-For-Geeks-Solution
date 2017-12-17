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
    int n,cnt,p;
    cin>>n;
    string s[105];
    int h[256];
    for(int i=0;i<256;i++){
        h[i]=0;
    }
    for(int i=0;i<n;i++) {
        cin>>s[i];
    }
    string ans="";
    for(int i = 0; i < 26;i++) {
        for(int j = 0; j < n; j++) {
            cnt=0;
            for(int k=0; k < s[j].length(); k++){
                    if(s[j][k] - 'a' == i){
                        cnt++;
                    }
            }
            if(j != 0) {
                h[i] = min(h[i],cnt);
            } else {
                h[i] = cnt;
            }
        }
        p = h[i];
        char c = i+'a';
        while(p--) {
            ans += c;
        }
    }
    if(ans.length() == 0){
        cout<<"no such string"<<endl;
        return 0;
    }
    sort(ans.begin(),ans.end());
    cout<<ans<<endl;

    return 0;
}
