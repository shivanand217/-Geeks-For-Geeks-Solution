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
int le[100005];
int ri[100005];
int main() {
    fast;
    int t;
    cin>>t;
    string s;
    while(t--) {
        cin>>s;
        memset(le,0,sizeof(le));
        memset(ri,0,sizeof(ri));
        int A=0,B=0;
        for(int i=0; i < s.length();i++) {
            if(s[i] == '.') {
                if(i==0) {
                    le[i]=0;
                } else {
                    le[i]=le[i-1];
                }
            } else {
                if(s[i]=='A'){
                    le[i]=1;
                } else {
                    le[i]=2;
                }
            }
            if(s[i] == 'A')
                A++;
            if(s[i] == 'B')
                B++;
        }
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == '.') {
                if(i == s.length()-1){
                    ri[i]=0;
                } else {
                    ri[i]=ri[i+1];
                }
            } else {
                if(s[i] == 'A'){
                    ri[i]=1;
                } else {
                    ri[i]=2;
                }
            }
        }
        for(int i=0; i < s.length(); i++){
            if(s[i] == '.'){
                if(le[i] == ri[i]){
                    if(le[i] == 1)
                        A++;
                    else if(le[i] == 2)
                        B++;
                }
            }
        }
        cout<<A<<" "<<B<<endl;
    }

    return 0;
}
