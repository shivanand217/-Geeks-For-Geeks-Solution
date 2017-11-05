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

int arr[mx5];
int Tree[2*mx5];

void build(int node, int s, int e) {

    if(s == e) {
        Tree[node] = arr[s];
        return;
    }

    int mid = ((s+e)/2);
    int left = 2*node;
    int right = left+1;

    build(left, s, mid);
    build(right, mid+1, e);

    Tree[node] = ( Tree[left]^Tree[right] );
}

int query(int node, int s, int e, int l, int r) {

    if(l == s && r == e) {
        return Tree[node];
    }

	int mid = ((s+e)/2);
    int left = 2*node;
    int right = left+1;

    if(r <= mid){
        return query(left, s, mid, l, r);
    }
    if(l > mid){
        return query(right, mid+1, e, l, r);
    }

    ll leftAns = query(left, s, mid, l, mid);
    ll rightAns = query(right, mid+1, e, mid+1, r);

    return (leftAns^rightAns);
}

int main() {
    int t,n,Q;
    int l,r,ans;
    si(t);

    while(t--) {
        si(n);
        for(int i=0; i<n; i++) {
			si(arr[i]);
        }
        build(1, 0, n-1);
        si(Q);

        while(Q--) {
            si(l), si(r);
            ans = 0;

            for(int i=0; i<n; i++) {
                for(int j=i; j<n; j++) {
					ll qu_ans = query(1, 0, n-1, i, j);

                    if(qu_ans >= l && qu_ans <= r) {
                        ans++;
                    }
                }
            }
            printf("%lld\n", ans);
		}
    }
   return 0;
}
