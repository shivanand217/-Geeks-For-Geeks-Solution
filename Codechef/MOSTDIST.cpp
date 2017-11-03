#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
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

// max heap
// sum , index, x, y
pair<int,pair<int,pair<int,int> > > k;
priority_queue<pair<int, pair<int,pair<int,int> > > > h1,h2,h3,h4;

ll solve(pair<int,pair<int,pair<int,int> > > p, ll x, ll y) {
    return (abs(p.ss.ss.ff - x) + abs(p.ss.ss.ss - y));
}

int main() {
    ll answer=0,q,x_,y_,n_,x,y,n;
	pair<int,pair<int,pair<int,int> > > p1,p2,p3,p4;
    cin>>q;

    vii v;
    v.push_back(mp(-1,-1));
    bool vis[mx6] = {false};
    char ch;

    while(q--) {

        cin>>ch;
        if(ch == '-') {
            cin>>n_;
            n = (n_^answer);
            vis[n]=true;

        } else if(ch == '+'){

            cin>>x_>>y_;
            x = (answer^x_);
            y = (answer^y_);
            //cout<<x<<" "<<y<<endl;
            v.pb(mp(x,y));

            h1.push(mp((x+y),mp(v.size()-1,mp(x,y))));
            h2.push(mp((x-y),mp(v.size()-1,mp(x,y))));
            h3.push(mp((-x+y),mp(v.size()-1,mp(x,y))));
            h4.push(mp((-x-y),mp(v.size()-1,mp(x,y))));

		} else if(ch == '?') {
            cin>>x_>>y_;
            x = (x_^answer);
            y = (y_^answer);
            //cout<<x<<" "<<y<<endl;

            while(vis[h1.top().second.first] == 1){
                h1.pop();
            }
            p1 = h1.top();

            while(vis[h2.top().second.first] == 1){
                h2.pop();
            }
            p2 = h2.top();

            while(vis[h3.top().second.first] == 1){
                h3.pop();
            }
            p3 = h3.top();

            while(vis[h4.top().second.first] == 1){
                h4.pop();
            }
            p4 = h4.top();

            ll ans_ = max4(solve(p1,x,y), solve(p2,x,y), solve(p3,x,y), solve(p4,x,y));
            cout<<ans_<<endl;
            answer = ans_;
		}

    }
	return 0;
}
