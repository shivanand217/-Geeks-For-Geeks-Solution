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
    int t;
    cin>>t;
    string s1,s2;
    while(t--) {
        string f="FLAME";
        int ha1[256],ha2[256];
        for(int i=0;i<256;i++) {
            ha1[i]=0;
            ha2[i]=0;
        }
        cin>>s1>>s2;
        int cnt=0;
        for(int i=0;i<s1.length();i++){
            ha1[(int)s1[i]]++;
        }
        for(int i=0;i<s2.length();i++){
            ha2[(int)s2[i]]++;
        }
        for(int i=0;i<256;i++){
            if(ha1[i]>0 && ha2[i]>0) {
                cnt += (ha1[i]+ha2[i]);
            }
        }
        cnt = (s1.length()+s2.length()-cnt)%5;
        if(cnt==1)
            cout<<"LFAME"<<endl;
        else if(cnt==2)
            cout<<"FLAME"<<endl;
        else if(cnt==3)
            cout<<"FALME"<<endl;
        else if(cnt==4)
            cout<<"FMALE"<<endl;
        else
            cout<<"FEAML"<<endl;
    }
    return 0;
}
