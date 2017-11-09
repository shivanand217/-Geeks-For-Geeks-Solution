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
bool avail[26][26];

int main() {

	std::ios::sync_with_stdio(false);
    int p,m;
    cin>>p;

	string S,T,backchod_input;
	char to,fr;

    while(p--) {
        memset(avail,false,sizeof(avail));

        for(int i=0;i<26;i++) {
			avail[i][i]=true;
        }

		cin>>S>>T;
		cin>>m;

        if(S.length()!=T.length()){
            cout<<"NO"<<endl;
            continue;
        }

		for(int i=0;i<m;i++) {
			cin>>backchod_input;
			to = backchod_input[0] , fr = backchod_input[backchod_input.length()-1];
			avail[to-'a'][fr-'a'] = true;
		}

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
				for(int j=0;j<26;j++){
                    avail[i][j] = ( avail[i][j] | (avail[i][k]&avail[k][j]) );
				}
            }
        }

		bool ans=true;
        for(int i=0;i<S.length();i++) {
             if(avail[S[i]-'a'][T[i]-'a'] == false) {
                ans=false;
             }
        }

        if(ans == false) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }

    return 0;
}
