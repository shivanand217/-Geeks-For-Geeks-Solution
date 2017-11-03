#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define mx5 100005
#define mx6 1000006
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;

int main() {
    int t,n,k,cnt;
    cin>>t;
    string sp,q;

    int p[26];
    int count_[26];
    vector<string> ans;

    while( t-- ) {

		ans.clear();
        memset(p, 0, sizeof(p));
        cin>>sp;
        cin>>n>>k;

		for( int i=0; i<sp.length(); i++ ){
            p[sp[i]-'a']++;
        }

        while(n--) {
            memset(count_, 0, sizeof(count_));
            cnt=0;
            cin>>q;

            for(int i=0; i<q.length(); i++) {
                count_[q[i] - 'a']++;
            }

            for(int i=0; i<26; i++) {
                if(p[i] > 0 && count_[i]>0)
                    cnt++;
            }

            if(cnt >= k){
                ans.push_back(q);
            }
        }

        if(ans.size() > 0){
            cout<<"Yes"<<endl;
            for(auto i: ans){
                cout<<i<<endl;
            }
        } else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
