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
    string x,y;
    while(t--) {
        cin>>x>>y;
        int flag=0,flag2=0;
        for(int i=0,j=0;i<x.length();i++){
            if(x[i]==y[j]) j++;
            if(j == y.length()){
                flag=1;
                break;
            }
        }
        reverse(y.begin(),y.end());
        for(int i=0,j=0;i<x.length();i++){
            if(x[i]==y[j]) j++;
            if(j == y.length()){
                flag2=1;
                break;
            }
        }
        if(flag==1 && flag2==1){
            cout<<"GOOD STRING"<<endl;
        } else {
            cout<<"BAD STRING"<<endl;
        }
    }
    return 0;
}
