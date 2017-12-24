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
#define ss second
#define ff first
using namespace std;
vector<pair<ll,ll> > v;
bool comp(pair<ll,ll> x,pair<ll,ll> y) {
    return (x.ss < y.ss);
}
int main() {
    ll n,kk,p,tmp,x,y;
    slli(n),slli(kk),slli(p);
    //v.resize(n + 10;
    for(ll i=1; i<=n; i++) {
        slli(tmp);
        v.push_back(make_pair(i,tmp));
    }
    sort(v.begin(),v.end(),comp);
    unordered_map<ll,ll> un;
    for(ll i=0; i<v.size(); i++) {
        un[v[i].ff] = i; // ff index of original array is at ith index in the sorted array
    }
    pair<ll,ll> k,m;
    ll comp=1;
    for(ll i=0; i < v.size(); i++) {
        k = v[i];
        if(i == 0) {
            k.ff = comp;
            v[i]=k;
        } else {
            k = v[i];
            m = v[i-1];
            if(abs(k.ss - m.ss) <= kk) {
                k.ff = comp;
                v[i] = k;
            } else {
                comp++;
                k.ff = comp;
                v[i]=k;
            }
        }
    }   ll k1,k2;
    //for(pair<ll,ll> p : v) {
      //  cout<<p.ff<<" "<<p.ss<<endl;
    // }
    while(p--) {
        slli(x),slli(y);
        k1=un[x];
        k2=un[y];
        if(v[k1].ff==v[k2].ff) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
