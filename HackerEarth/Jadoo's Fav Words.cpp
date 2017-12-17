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
    int k;
    cin>>k;
    vector<string> d(k);
    for (int i=0;i<k;i++){
        cin>>d.at(i);
    }
    int n;
    cin>>n;
    vector<string> s(n);
    string a;
    int x;
    for (int i=0;i<n;i++){
        cin>>a;
        for (int j=0;j<k;j++){
            if (a==d.at(j)||a==(d.at(j)+',')||a==(d.at(j)+'.')){
                transform(a.begin(), a.end(), a.begin(), ::toupper);
            }
        }
        s.at(i)=a;
    }

    cout<<s.at(0);
    for (int i=1;i<n;i++){
        cout<<' '<<s.at(i);
    }

    return 0;
}

