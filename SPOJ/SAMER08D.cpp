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

int dp[1005][1005];

int main() {
    fast;
    int k,i,j,k1,k2;
    string s1,s2;
    int c;
    while(1) {
        cin>>k;

        if(k==0) {
            cout<<"0"<<endl;
            return 0;
        }

        cin>>s1>>s2;
        k1 = s1.length(), k2 = s2.length();

        for(i=0; i<=k1; i++){
            for(j=0; j<=k2; j++){
                dp[i][j] = 0;

                if(i==0 || j==0)
                    continue;

                c=1;
                // k or more characters must have to be common
                while(i-c>=0 && j-c>=0 && s1[i-c]==s2[j-c]){
                    if(c >= k)
                        dp[i][j] = max(dp[i][j],c+dp[i-c][j-c]);
                    c++;
                }

                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }

        cout<<dp[k1][k2]<<endl;
    }

    return 0;
}
