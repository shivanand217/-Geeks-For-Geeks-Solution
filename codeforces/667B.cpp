#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define REP(i, n) for(int i = 0; i < (n); i++)
#define mp make_pair
#define ll long long
#define boostio std::ios::sync_with_stdio(false);cin.tie(NULL);
#define tt int n;cin>>n;while(n--)
#define ff first
#define ss second
#define pii pair<int,int>
#define MOD 1000000007

ll arr[100005];

int main()
{
boostio;
ifstream ifile("input.txt");
	if(ifile) freopen("input.txt","rt",stdin);
	#ifdef ONLINE_JUDGE
		if(ifile) freopen("output.txt","wt",stdout);
	#endif

/*freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);*/
int n;
priority_queue<ll,std::vector<ll> , greater<ll> > pq;
ll maxn=-1000000000LL;

cin>>n;
ll tmp;

REP(i,n)
{
    cin>>arr[i];
    if(maxn<arr[i])
        maxn=arr[i];
}

ll sum=0;
for(int i=0;i<n;i++)
{
    if(arr[i]!=maxn)
        sum+=arr[i];
}

ll ans=maxn+1;
ans-=sum;

cout<<ans<<endl;

return 0;
}
