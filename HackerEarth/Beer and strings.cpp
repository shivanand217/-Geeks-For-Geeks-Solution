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
    string beer,str;
    cin>>beer;
    int h1[256];
    for(int i=0;i<256;i++) {
        h1[i]=0;
    }
    for(int i=0;i<beer.length();i++) {
        h1[beer[i]-'a']++;
    }
    int t;
    cin>>t;
    int h2[256];
    int an=0;
    while(t--) {
        for(int i=0;i<256;i++) {
            h2[i]=0;
        }
        cin>>str;
        for(int i=0;i<str.length();i++) {
            h2[str[i]-'a']++;
        }
        bool ans=true;
        for(int i=0;i<256;i++) {
            if(h2[i] > 0) {

                 if(h2[i] > h1[i]) {
                    ans=false;
                    break;
                 }
            }
        }
        if(ans == true){
            an++;
        }
    }
    cout<<an;
    return 0;
}
