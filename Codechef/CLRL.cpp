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
    int t,n,p,tmp;
    cin>>t;
    int prev,leftlimit,rightlimit;
    while(t--) {
        cin>>n>>p;
        bool ans=true;
        leftlimit=-1;
        rightlimit=-1;
        for(int i=0; i<n; i++) {
            cin>>tmp;
            if(i == 0) {
                prev=tmp;
            } else {
                if(prev < tmp) {
                    leftlimit = prev;
                } else {
                    rightlimit = prev;
                }
                if(rightlimit != -1) {
                    if(tmp > rightlimit){
                        ans=false;
                    }
                }
                if(leftlimit != -1) {
                    if(tmp < leftlimit){
                        ans=false;
                    }
                }
            }
            prev = tmp;
        }
        if(ans == false) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }

    return 0;
}
