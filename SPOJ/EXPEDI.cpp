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
#define mx4 5004
#define rep(i,n) for(int i=0; i<n; i++)
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

    int t,n,a,b,dist,fuel;
    si(t);

    vector<pair<int,int> > vec;
    set<pair<int,int> > st;

    while(t--) {

		bool an = true;

        vec.clear();
        st.clear();

        si(n);
        for(int i=0; i<n; i++){
            si(a), si(b);
            vec.pb(mp(a,b));
        }

        sort(vec.begin(), vec.end());
        si(dist), si(fuel);

        int start=dist;
        int cnt=n-1;
        int ans=0;

        for(int i=0; i<dist; i++, fuel--) {

            if(cnt != -1){
                if(start - vec[cnt].ff == i){
                    st.insert(mp(vec[cnt].ss, vec[cnt].ff));
                    cnt--;
                }
            }

            if(fuel == 0){

                if(st.size() == 0){
                    an = false;;
                    break;
                }

                ans++;
                auto it = st.end();
                it--;
                fuel += (*it).ff;
                st.erase(it);
            }
        }

        if(an == false){
            printf("-1\n");
        } else {
			printf("%d\n", ans);
        }

    }
	return 0 ;
}

