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
#define fck std::ios::sync_with_stdio(false);
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

int freq[100009][26];
int ind[102],arr[100009];
int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

// iterative power func 0.25s faster than recursive pow
int power(int base,int exp,int m) {
    int res=1;
    while(exp>0) {
        if((exp&1)){
            res = ((ll)(res)*base)%m;
        }
        exp=exp/2;
        base = ((ll)(base)*base)%m;
    }
    return res;
}

/**
// using recursive modular power gives time of 0.73s but by iterative its 0.48s
int power(int x,int y,int m) {
    if(y==0){
		return 1;
    }
    int p = power(x,y/2,m);
    p = ((ll)p*p)%m;
    if(y%2==0){
        return p;
    } else {
        return ((ll)(x)*p)%m;
    }
}**/

vector<int> factorise(int n) {
    vector<int> ans(25);
    for(int i=0;i<4;i++) {
        if(n % primes[i] == 0){
            int c=0;
            while(n%primes[i] == 0){
                c++;
                n/=primes[i];
            }
            ans[i]=c;
        }
    }
    if(n > 1) {
        ans[ind[n]]++;
    }
    return ans;
}

void pre(int n) {
    for(int i=1;i<=n;i++) {
        vector<int> f = factorise(arr[i]);
        for(int j=0;j<f.size();j++) {
            freq[i][j]=freq[i-1][j]+f[j];
        }
    }
}

int solve(int l,int r,int m) {
    vector<int> f(25);
    for(int i=0;i<25;i++) {
        f[i]=freq[r][i]-freq[l-1][i];
    }
    int ans=1;
    for(int i=0;i<25;i++) {
        ans=((ll)(ans)*(power(primes[i],f[i],m)))%m;
    }
    return ans;
}

int main() {
   int c,n,t,l,r,q,k,p,m;
   for(int i=0;i<25;i++) {
        ind[primes[i]] = i;
   }

   si(n);
   for(int i=1;i<=n;i++) {
        si(arr[i]);
   }
   pre(n);
   si(q);

   while(q--) {
        si(l), si(r), si(m);
        printf("%d\n",solve(l,r,m));
   }

   return 0;
}
