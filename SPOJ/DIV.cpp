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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

int  pp[mx6+1];
vector <int> sp;

void pre_sieve()
    sp.resize(mx6);
    for( ll i = 2; i < mx6; i++ )
        if( pp[i] == 0 )
        {
            sp[i] = i;
            for(ll j = i*i; j < mx6; j += i)
                if ( pp[j] == 0 )
                {
                    sp[j] = i;
                    pp[j] = 1;
                }
        }
}

int main()
{
	vector<int>  ans;
	pre_sieve();

	for(int i = 2; i < mx6; i++)
	{
		if(!pp[i]) continue;
		int num = i;
		ll fnum = 1ll;
		map<int,int> mm;
		while(num > 1)
		{
			mm[sp[num]]++;
			num /= sp[num];
		}
		for(auto ii: mm)
			fnum *= (ii.ss+1);

		if(!pp[fnum])
			continue;

		int step = 0;
		int p, q;

		while(fnum > 1)
		{
			step++;
			if(step == 1)
				p = sp[fnum];
			else if(step == 2)
				q = sp[fnum];

			fnum /= sp[fnum];
			if(step == 2)
				break;
		}

		if(fnum == 1 && p != q)
		{
			ans.pb(i);
		}
	}

    for(int i=8; i<ans.size(); i+=9) {
        printf("%d\n",ans[i]);
    }

    return 0;
}
