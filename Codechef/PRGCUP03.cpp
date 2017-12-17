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

    unordered_map<string,vector<string> > un;
    un["scissors"].pb("paper");
    un["paper"].pb("rock");
    un["rock"].pb("moon");
    un["moon"].pb("sun");
    un["sun"].pb("scissors");
    un["scissors"].pb("moon");
    un["moon"].pb("paper");
    un["paper"].pb("sun");
    un["sun"].pb("rock");
    un["rock"].pb("scissors");

    // Akira Hideki

    while(t--)  {
        cin>>s1>>s2;
        if(s1 == s2) {
            cout<<"drew"<<endl;
            continue;
        }
        bool f=false,s=false;
        for(int i=0; i < un[s1].size(); i++) {
            if(un[s1][i] == s2) {
                f = true;
                break;
            }
        }
        for(int i=0; i < un[s2].size(); i++) {
            if(un[s2][i] == s1){
                s = true;
                break;
            }
        }
        if(f == true && s == true){
            cout<<"drew"<<endl;
            continue;
        }
        if(f == true){
            cout<<"akira"<<endl;
            continue;
        }
        if(s == true){
            cout<<"hideki"<<endl;
            continue;
        }
        if(f == false && s == false){
            cout<<"drew"<<endl;
            continue;
        }
    }

    return 0;
}
