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
    int n;
    cin>>n;
    string s,ans="";

    for(int i=0; i<n; i++) {
        cin>>s;
        int k = s.length();
        s += s;
        ans="";
        string dummy;
        int indx;
        for(int j=0; j<k; j++) {
            dummy = s.substr(j, k);
            if(j == 0) {
                indx = j+1;
                ans=dummy;
            } else {
                if(dummy < ans){
                    ans = dummy;
                    indx = j+1;
                }
            }
        }
        cout<<indx<<endl;
    }

    return 0;
}
