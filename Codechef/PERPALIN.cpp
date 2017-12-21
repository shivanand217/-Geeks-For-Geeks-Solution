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
    int t;
    cin>>t;
    int n,p;
    char s[100005];
    while(t--) {
        cin>>n>>p;
        if( n == 1 || p == 1 || p == 2 || p > n || (n%p != 0) ) {
            cout<<"impossible"<<endl;
            continue;
        }
        if(n == 2 && p == 2) {
            cout<<"impossible"<<endl;
            continue;
        }
        int i = 0 , j = p-1;
        int flag = 0;
        while(i <= j) {
            if(i != j){
                if(flag == 0) {
                    s[i]='a';
                    s[j]='a';
                    i++,j--;
                } else {
                    s[i]='b';
                    s[j]='b';
                    i++,j--;
                }
            } else {
                if(flag == 0) {
                    s[i]='a';
                } else {
                    s[i]='b';
                }
                i++,j--;
            }
                flag = 1-flag;
        }
        int cur = n-p;
        cur /= p;
        string ans="";
        j = p-1;
        for(i=0; i <= j; i++) {
            ans += s[i];
        }
        cout<<ans;
        while(cur--) {
            cout<<ans;
        }   cout<<endl;
    }

    return 0;
}
