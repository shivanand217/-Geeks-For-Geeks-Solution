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

int arr[mx5];
int Treemax[4*mx5] , Treemin[4*mx5];

void build(int node,int s,int e) {

    if(s == e) {
        Treemax[node] = arr[s];
        Treemin[node] = arr[s];
        return;
    }

    int mid = ((s+e)/2);
    build(2*node+1 , s , mid);
    build(2*node+2 , mid+1 , e);

    Treemin[node] = min(Treemin[2*node+1] , Treemin[2*node+2]);
    Treemax[node] = max(Treemax[2*node+1] ,  Treemax[2*node+2]);
}

int queryMax(int node,int s,int e,int lo,int hi) {

    if(e < lo || hi < s) {
        return -1;
    }

    if(lo <= s && e <= hi){
        return Treemax[node];
    }

    int mid = ((s+e)/2);
    int p = queryMax(2*node+1 , s, mid, lo, hi);
    int q = queryMax(2*node+2 , mid+1 ,e, lo, hi);

    return max(p , q);
}

int queryMin(int node,int s,int e,int lo,int hi) {

    if(e < lo || hi < s)
        return 1e9;

    if(lo <= s && e <= hi) {
        return Treemin[node];
    }

    int mid = ((s+e)/2);
    int p = queryMin(2*node+1, s, mid, lo, hi);
    int q = queryMin(2*node+2, mid+1, e, lo, hi);

    return min(p , q);
}

int main() {
   int n,q,x,y;
   si(n), si(q);

   for(int i=0;i<n;i++) {
        si(arr[i]);
   }

   build(0,0,n-1);

   while(q--) {
        si(x), si(y);

        int m1 = queryMax(0,0,n-1,x,y);
        int m2 = queryMin(0,0,n-1,x,y);

        printf("%d\n", abs(m1 - m2));
   }

   return 0;
}
