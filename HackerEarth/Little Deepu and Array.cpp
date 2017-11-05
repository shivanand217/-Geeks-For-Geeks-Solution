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

// policy based data structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

int arr[mx5];
int Tree[4*mx5];
int lazy[4*mx5];

void build(int i,int s,int e) {

    if(s > e)
		return;
    if(s == e) {
        Tree[i]=arr[s];
        return;
    }
    int mid=((s+e)/2);
    build(2*i,s,mid);
    build(2*i+1,mid+1,e);
    Tree[i]=min(Tree[2*i],Tree[2*i+1]);

}

void update(int i,int s,int e,int l,int r,int x,int value) {
    if(s > e || s > r || e < l)
		return;
    if(lazy[i] != 0) {
        Tree[i] += lazy[i];
        if(s != e) {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
			lazy[i] = 0;
    }
    if(Tree[i]>x) {
        Tree[i] += value;
        if(s!=e) {
            lazy[2*i] += value;
            lazy[2*i+1] += value;
        }
		return;
    }
    if(s == e)
		return;
    int mid=((s+e)/2);

    update(2*i,s,mid,l,r,x,value);
    update(2*i+1,mid+1,e,l,r,x,value);
    Tree[i] = min(Tree[2*i],Tree[2*i+1]);

}

int query(int i,int s,int e,int l,int r) {

    if(s > e || l > e || r < s)
		return INT_MAX;

    if(lazy[i]!=0) {
        Tree[i] += lazy[i];
        if(s!=e){
            lazy[2*i]+=lazy[i];
            lazy[2*i+1]+=lazy[i];
        }
			lazy[i]=0;
    }

    if(l<=s && e<=r) {
        return Tree[i];
    }

    int mid=((s+e)/2);
    int p1=query(2*i,s,mid,l,r);
    int p2=query(2*i+1,mid+1,e,l,r);
    return min(p1,p2);

}

int main() {

   memset(lazy,0,sizeof(lazy));
   memset(Tree,0,sizeof(Tree));

   int n,Q,x,a;
   si(n);
   vector<pair<int,int> > p;

   for(int i=0;i<n;i++) {
        si(a);
        p.pb(mp(a,i+1));
   }

	sort(p.begin(),p.end());
   for(int i=0;i<n;i++) {
        arr[i] = p[i].ff;
   }

   build(1,0,n-1);
   si(Q);

   while(Q--) {
        si(x);
        update(1,0,n-1,0,n-1,x,-1);
   }

   for(int i=0;i<n;i++) {
        p[i].ff = query(1,0,n-1,i,i);
        swap(p[i].ff,p[i].ss);
   }
	sort(p.begin(),p.end());

   for(int i=0;i<n;i++) {
        printf("%d ",p[i].ss);
   }	putchar('\n');

   return 0;
}
