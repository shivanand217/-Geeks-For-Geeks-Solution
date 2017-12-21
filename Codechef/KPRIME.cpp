#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

int prime[100002];
int  marked[100002][6];

void precompute() {
    prime[0] = prime[1] = 0;
    for(int i=2; i < 100002; i++) {
        prime[i] = 0;
    }
    for(int i=2; i < 100002; i++) {
        if(prime[i] == 0) {
            for(ll j=i; j < 100002; j += (long long)i) {
                prime[j]++;
            }
        }
    }
    /** prefix computation **/
    for(int i=2; i < 100002; i++) {
        for(int j=0; j < 6; j++) {
            marked[i][j]=0;
            if(prime[i] == j) {
                marked[i][j] = marked[i-1][j] + 1;
            } else {
                marked[i][j] = marked[i-1][j];
            }
        }
    }
}

int main() {
    int t,a,b,k;
    scanf("%d",&t);

    precompute();
    while(t--) {
        scanf("%d %d %d", &a, &b, &k);
        printf("%d\n", marked[b][k] - marked[a-1][k]);
    }

    return 0;
}
