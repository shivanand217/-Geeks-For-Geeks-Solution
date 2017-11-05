#include<bits/stdc++.h>
#define ff first
#define ss second
#define mx6 1000005

using namespace std;

typedef long long int ll;

pair<ll,ll> tree[300000];
ll arr[200000];
pair<ll,ll> p1,p2,p3,ans;

void build(ll i, ll st, ll en) {

    if(st == en)
    {
        if(arr[st]%2 == 0) {
            tree[i].ff=1;
            tree[i].ss=0;
        } else {
        	tree[i].ff=0;
        	tree[i].ss=1;
        }
        return;
    }

	ll mid = ((st+en)/2);

	build(2*i, st, mid);
	build(2*i+1, mid+1, en);

	tree[i].ff = tree[2*i].ff + tree[2*i+1].ff;
	tree[i].ss = tree[2*i].ss + tree[2*i+1].ss;
}

void update(ll i, ll st, ll en, ll idx, ll val) {

    if(st == en) {
        arr[idx] = val;

        if(arr[idx]%2 == 0) {
            tree[i].ff=1;
            tree[i].ss=0;
        } else {
            tree[i].ff=0;
            tree[i].ss=1;
        }

        return;
    }

	ll mid = ((st + en)/2);

	if(idx <= )
		update(2*i, st, mid, idx, val);
	else
		update(2*i+1, mid+1, en, idx, val);

    tree[i].ff = tree[2*i].ff + tree[2*i+1].ff;
    tree[i].ss = tree[2*i].ss + tree[2*i+1].ss;
}

pair<ll,ll> query(ll i, ll st, ll en, ll l, ll r) {

    if(st == l && en == r)
        return tree[i];

    ll mid = (st + en) / 2;

    if(r <= mid){
        return query(2*i, st, mid, l, r);
    }
    if(l > mid){
        return query(2*i+1, mid+1, en, l, r);
    }

    p1 = query(2*i, st, mid, l, mid);
    p2 = query(2*i+1, mid+1, en, mid+1, r);

    ll f1,s1;

    f1 = p1.ff + p2.ff;
    s1 = p1.ss + p2.ss;

    p3 = make_pair(f1,s1);

    return p3;
}


int main() {

    ll n,tmp,t,a,b,idx,val;
    cin>>n;

    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    build(1,1,n);
    cin>>t;

    while(t--)
    {
        int type;
        cin>>type;

        if(type == 1 || type == 2)
        {
            cin>>a>>b;

            pair<ll,ll> ans = query(1,1,n,a,b);

            if(type == 1){
                cout<<ans.ff<<endl;
            } else {
				cout<<ans.ss<<endl;
            }
        }
        else if(type == 0)
        {
            cin>>idx>>val;
            update(1,1,n,idx,val);
        }

    }

    return 0;
}
