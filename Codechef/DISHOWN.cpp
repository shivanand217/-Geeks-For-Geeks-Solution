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

int t,n,Q,x,y,type,root1,root2;

int main(){

    si(t);

    while(t--) {
        si(n);
        int par[n+1];
        int S[n+1];

        for(int i=0; i<n; i++){
            par[i]=i;
        }

        for(int i=0; i<n; i++) {
            si(S[i]);
		}

        si(Q);
        while(Q--) {

            si(type);
            if(type == 0) {
                si(x), si(y);
                x--, y--;

                while(1) {
                    if(x == par[x]){
						root1 = x;
						break;
                    } else {
                    	par[x] = par[par[x]];
                    	x = par[x];
                    }
                }

                while(1) {
                    if(y == par[y]){
						root2 = y;
						break;
                    } else {
                    	par[y] = par[par[y]];
                    	y = par[y];
                    }
                }

                if(root1 == root2){
                    printf("Invalid query!\n");

                } else {
                    if( S[x] > S[y] ){
                        par[root2] = root1;
                    } else if( S[y] > S[x] ){
						par[root1] = root2;
                    }
                }

            } else {
                si(x);
                x--;

                while(1) {
                    if(x == par[x]){
						root1 = x;
						break;
                    } else {
                    	par[x] = par[par[x]];
                    	x = par[x];
                    }
                }

                printf("%d\n", (root1+1));
            }
        }
    }

   return 0;
}
