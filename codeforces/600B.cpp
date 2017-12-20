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
    int n,m,tmp;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>tmp;
        a[i]=tmp;
    }
    sort(a.begin(),a.end());
    for(int j=0; j < m;j++) {
        cin>>tmp;
        b[j]=tmp;
    }
    vector<int> :: iterator up;
    for(int j=0; j<m; j++){
        up = upper_bound(a.begin(),a.end(),b[j]);
        cout<<up-a.begin()<<" ";
    }   cout<<endl;

    return 0;
}
