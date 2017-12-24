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

string s1,s2,s3,s4,s5;

long long api(string s) {
    ll num=0LL;
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i]))
            return -1;
        num = num*10LL + (s[i]-'0');
    }
    return num;
}

int main() {
    fast;
    int t;
    cin>>t;
    ll v1,v2,v3;

    while(t--) {
        cin>>s1>>s2>>s3>>s4>>s5;
        v1 = api(s1);
        v2 = api(s3);
        v3 = api(s5);
        if(v1<0) {
            v1 = v3 - v2;
        }
        else if(v2 < 0) {
            v2=v3-v1;
        } else if(v3 < 0) {
            v3=v1+v2;
        }
        cout<<v1<<" + "<<v2<<" = "<<v3<<endl;
    }

    return 0;
}
