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

int a[100005];

int main() {
    //fast;
    int t,n,i;
    long long int sum,sumt;

    scanf("%d",&t);
    cin>>t;
    multimap<int,int> m;
    multimap<int,int>::iterator it;

    while(t--) {
        scanf("%d",&n);
      //  cin>>n;
        sumt = 0;

        for(i = 0; i < n; i++) {
            //cin>>a[i];
            scanf("%d",&a[i]);
        }

        for(i = 0; i < n; i++) {
                sum = 0;
            for(it = m.begin(); it != m.end(); it++) {
                if(it->first >= a[i]) {
                    break;
                }
                else {
                    sum = sum + it->first;
                }
            }

            m.insert(pair<int,int> (a[i],0));
            sumt = sumt + sum;
        }

        printf("%lld\n",sumt);

        //cout<<sumt<<endl;
        m.clear();
    }

    return 0;
}
