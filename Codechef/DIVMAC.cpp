/** k,c,u,f are my favourite variables **/

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
#define getx getchar_unlocked
#define putx putchar_unlocked
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

int n,m,L,R,type,t,ans;
int arr[mx6];
int LeastPrimeDivisor[mx6];
int Tree[mx6];

void init() {
   LeastPrimeDivisor[1] = 1;
   for(int i=2;i<=1000005;i++) {
        if(LeastPrimeDivisor[i]==0) {
            for(int j=i; j<=1000005; j+=i)
                if(LeastPrimeDivisor[j]==0)
                    LeastPrimeDivisor[j]=i;
        }
    }
}

void build(int node, int s, int e) {
    if(s > e)
		return;

    if(s == e) {
        if(LeastPrimeDivisor[arr[s]] == 0)
            Tree[node] = 1;
        else
            Tree[node] = LeastPrimeDivisor[arr[s]];
        return;
    }

    int mid = ((s+e)/2);
    int left = 2*node;
    int right = left+1;

    build(left, s, mid);
    build(right, mid+1, e);

    Tree[node] = max( Tree[left] , Tree[right] );

}

int query(int node, int s, int e, int lo, int hi) {
    if(Tree[node] == 1) {
        return 1;
    }

    if(lo == s && hi == e) {
        return Tree[node];
    }

    int mid = ((s+e)/2);
    int left = 2*node;
    int right = left+1;

    if(lo > mid) {
        return query( right, mid+1, e, lo, hi);
    }

	if(hi <= mid) {
        return query(left, s, mid, lo, hi);
	}

    int leftAns = query(left, s, mid, lo, mid);
    int rightAns = query(right, mid+1, e, mid+1, hi);

    return max( leftAns , rightAns );
}

void update(int node, int s, int e, int lo, int hi) {
    if(s > e || lo > e || hi < s)
            return;

	if(Tree[node] == 1) {
		return;
	}

    if(s == e) {
        int tmp = arr[s];
        if(LeastPrimeDivisor[tmp] != 0) {
            arr[s] = (tmp/LeastPrimeDivisor[tmp]);
        }

        if(LeastPrimeDivisor[arr[s]] == 0) {
            Tree[node] = 1;
        } else {
            Tree[node]=LeastPrimeDivisor[arr[s]];
        }
		return;
    }

    int mid = ((s+e)/2);
    int left = 2*node;
    int right = left+1;

    update(left , s, mid, lo, hi);
    update(right, mid+1, e, lo, hi);

    Tree[node] = max( Tree[left] , Tree[right] );
}

inline int getint(){
    char _c;
    int _x=0;
    _c=getx();
    while (_c<=' ') _c=getx();
    while (_c>='0'){ _x=10*_x+(_c-'0'); _c=getx();}
    return _x;
}

int main() {

   t = getint();
   memset(LeastPrimeDivisor,0,sizeof(LeastPrimeDivisor));
   init();

	while(t--) {
        memset(Tree,0,sizeof(Tree));

		n = getint();
		m = getint();

        for(int i=0; i<n; i++) {
            arr[i] = getint();
        }
			build(1, 0, n-1);

        for(int i=0; i<m; i++) {
            type = getint();

            if(type == 0) {

                L = getint();
                R = getint();
                L--, R--;

                update(1, 0, n-1, L, R);

            } else {
                L = getint();
                R = getint();
                L--, R--;

                int ans = query(1, 0, n-1, L, R);

                printf("%d\n",ans);
            }
        }
   }
   return 0;
}
