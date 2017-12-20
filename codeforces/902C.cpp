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
int a[200005];
int main() {
    int n;
    cin>>n;
    bool fl=true;
    for(int i=0; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i] > 1 && a[i-1] > 1){
            fl=false;
            break;
        }
    }
    if(fl == true) {
        cout<<"perfect"<<endl;
        return 0;
    }
    cout<<"ambiguous"<<endl;
    cout<<"0 ";
    int x=1;
    int cnt=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i];j++){
            cout<<cnt<<" ";
            x++;
        }
        cnt=x;
    }
    cout<<endl;
    cout<<"0 ";
    cnt=1;
    x=1;
    fl = true;
    for(int i=1; i <= n; i++) {
        if(a[i] > 1 && a[i-1] > 1 && fl == true){
            fl=false;
            for(int j=0; j<a[i]-1; j++){
                cout<<cnt<<" ";
                x++;
            }
            cout<<cnt-1<<" ";
            x++;
        } else {
            for(int j=0; j<a[i]; j++){
                cout<<cnt<<" ";
                x++;
            }
        }
        cnt=x;
    }

    return 0;
}
