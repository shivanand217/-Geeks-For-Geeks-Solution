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
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

ll ar[100000];
pair<ll, ll> tree[1000000];

void build( ll node , ll start , ll end ){

	if( start == end ){
		tree[node].ff = tree[node].ss = inf;
		if( ar[start] % 2 == 0 ){
			tree[node].ss = ar[start];
		}
		else{
			tree[node].ff = ar[start];
		}
		return;
	}
	else {
		ll mid = ( start + end ) / 2;
		build( node * 2 , start , mid );
		build( node * 2 + 1 , mid + 1 , end );
		tree[node].ss = max ( tree[node * 2].ss , tree[ node * 2 + 1].ss );
		tree[node].ff = max ( tree[ node * 2].ff , tree[node * 2 + 1].ff );
	}
}

pair<ll, ll> query( ll node , ll start , ll end , ll l , ll r ){

	ll mid = ( start + end ) / 2;
	if( start >= l && end <= r ){
		return tree[node];
	}
	else if( r <= mid ){
		return query( node * 2 , start , mid , l , r );
	}
	else if( l > mid ){
		return query( node * 2 + 1 , mid + 1 , end , l , r );
	}
	else{
		pair<ll, ll> q1 , q2 , q3;
		q1 = query( node * 2 , start , mid , l , r );
		q2 = query( node * 2 + 1 , mid + 1 , end , l , r );
		q3.ss = max ( q1.ss , q2.ss );
		q3.ff = max ( q1.ff , q2.ff );
		return q3;
	}
}

void update( ll node ,ll start ,ll end ,ll index , ll data ){

    if( start > index || end < index || start > end ){
        return;
    }
	if( start == end && start == index ){
	    tree[node].ff = tree[node].ss = inf;
		if( data % 2 == 0 ){
			tree[node].ss = data;
		}
		else{
			tree[node].ff = data;
		}
	}
	else{
		ll mid = ( start + end ) / 2;
		update( node * 2 , start , mid , index , data );
		update( node * 2 + 1 , mid + 1 , end , index , data );
		tree[node].ss = max ( tree[node * 2].ss , tree[ node * 2 + 1].ss );
		tree[node].ff = max ( tree[ node * 2 + 1].ff , tree[node * 2].ff );
	}
}
int main() {

	ll n , q;
	scanf("%lld%lld", &n , &q);

	for( ll i = 1; i <= n; i++ ){
		scanf("%lld", &ar[i] );
	}

	build( 1 , 1 , n );

	while( q-- ){

		ll Q , l , r;

		scanf("%lld%lld%lld", &Q , &l , &r );

		if( Q == 3 || Q == 2 ){
			pair<ll,ll> ans = query( 1 , 1 , n , l , r );
			if( Q == 2 ){
				if( ans.ss == inf ){
					printf("DNE\n");
				}
				else{
				    printf("%lld\n", ans.ss );
				}
			}
			else if( Q == 3 ){
				if( ans.ff == inf ){
					printf("DNE\n");
				}
				else{
				    printf("%lld\n", ans.ff );

				}
			}
		}
		else if ( Q == 1 ){
			update( 1 , 1 , n , l , r );
		}
	}
}
