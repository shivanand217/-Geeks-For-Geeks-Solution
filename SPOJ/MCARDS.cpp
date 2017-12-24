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

   /** #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif **/

    fast;
    int co,n;
    cin>>co>>n;

    vector<int> a,b,c,d;
    vector<int> table;

    table.resize(n+1);
    int color,tmp;
    int total = n*co;

    for(int i=1; i <= total; i++) {
        cin>>color>>tmp;
        if(color==1) {
            a.push_back(tmp);
        }
        if(color==2) {
            b.push_back(tmp);
        }
        if(color==3) {
            c.push_back(tmp);
        }
        if(color==4){
            d.push_back(tmp);
        }
    }

    int sum = 0;

    /** LIS concept **/
    if(a.size() > 0) {
        fill(table.begin(), table.end(), 1);
        int maxx = 1;
        for(int i=1; i < a.size(); i++) {
            for(int j=0; j < i; j++) {
                if(a[i] > a[j] && table[i] < table[j] + 1){
                    table[i] = table[j] + 1;
                    maxx = max(maxx, table[i]);
                }
            }
        }
        int mov=0;
        mov = a.size() - maxx;
        cout<<mov<<endl;
        sum += mov;
    }

    if(b.size() > 0) {
        fill(table.begin(), table.end(), 1);
        int maxx = 1;
        for(int i=1; i < b.size(); i++) {
            for(int j=0; j<i; j++) {
                if(b[i] > b[j] && table[i] < table[j] + 1){
                    table[i] = table[j] + 1;
                    maxx = max(maxx, table[i]);
                }
            }
        }
        int mov=0;
        mov = b.size() - maxx;
        cout<<mov<<endl;
        sum += mov;
    }

    if(c.size() > 0) {
        fill(table.begin(),table.end(),1);
        int maxx = 1;
        for(int i=1; i<c.size(); i++) {
            for(int j=0; j<i; j++) {
                if(c[i] > c[j] && table[i] < table[j] + 1){
                    table[i] = table[j] + 1;
                    maxx = max(maxx, table[i]);
                }
            }
        }
        int mov=0;
        mov = c.size() - maxx;
        sum += mov;
    }

    if(d.size() > 0) {
        fill(table.begin(),table.end(),1);
        int maxx = 1;
        for(int i=1; i < d.size(); i++) {
            for(int j=0; j<i; j++) {
                if(d[i] > d[j] && table[i] < table[j] + 1){
                    table[i] = table[j] + 1;
                    maxx = max(maxx, table[i]);
                }
            }
        }
        int mov=0;
        mov = d.size() - maxx;
        sum += mov;
    }

    cout<<sum<<endl;

    return 0;
}
