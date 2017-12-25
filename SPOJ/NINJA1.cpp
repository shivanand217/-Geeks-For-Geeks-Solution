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
ll a[100005],b[100005];
int main() {
    fast;
    int t,n;
    cin>>t;
    vector< int > ans;

    while(t--) {
        cin>>n;
        for(int i = 0; i < n ; i++) {
            cin>>a[i];
        }
        for(int j = 0; j < n ; j++) {
            cin>>b[j];
        }

        bool flag = true;
        ll prev = -1;

        for(int i=0; i < n && flag ; i++) {
            if( a[i] > b[i] )
                swap(a[i], b[i]);
            if( a[i] >= prev )
                prev = a[i];
            else if( b[i] >= prev )
                prev = b[i];
            else
                flag = false;
        }

        /**
        int i = 0, j = 0, cnt = 0;
        bool flag = true;
        ans.clear();

        while(i < n && j < n && cnt != n) {
            if(a[i] < a[j]) {
                if( ans.size() > 0 && a[i] > ans.back() ) {
                    ans.pb(a[i]);
                    i++;
                    cnt++;
                } else if(ans.size() > 0 && a[i] < ans.back()){
                    i++;
                }
                if(ans.size() == 0){
                    ans.pb(a[i]);
                    i++;
                    cnt++;
                }
            } else {
                if(ans.size() > 0 && a[j] > ans.back()) {
                    ans.pb(a[j]);
                    j++;
                    cnt++;
                }
                if(ans.size() == 0){
                    ans.pb(a[j]);
                    j++;
                    cnt++;
                }
            }
        } **/
        if(flag == true) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
