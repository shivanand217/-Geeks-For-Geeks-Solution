#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define ff first
#define ss second
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
    int n,tmp=0,k=5;
    cin>>n;
    string s,p;
    map<string,int> m;
    while(n--) {
        getline(cin,s);
        int i=0,j=0;
        tmp=0;
        while(i < s.length()) {
            tmp=-1;
            j=0;
            if(s[i]=='#') {
                tmp = i+1;
                i++;
                while(s[i] != ' ' && i < s.length()) {
                    i++;
                    j++;
                }
                p = s.substr(tmp,j);
                m[p]++;
            } else {
                i++;
            }
        }
    }
    priority_queue<pair<int,string> > pq;
    for(auto it=m.begin(); it!=m.end(); it++) {
        pq.push(make_pair(it->ss,it->ff));
    }
    vector<string> ans;
    int i=0;
    pair<int,string> lp;
    while(i < k) {
        lp = pq.top();
        ans.pb(lp.ss);
        pq.pop();
        i++;
    }
    sort(ans.begin(),ans.end());
    for(i=0;i<ans.size();i++) {
        cout<<"#"<<ans[i]<<endl;
    }
    return 0;
}
