#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
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

typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
int cnt[100005];
int a[100005];

int main() {
    int n,tmp;
    scanf("%d", &n);
    memset(cnt,0,sizeof(cnt));

    for(int i = 0; i < n; i++) {
        scanf("%d",&tmp);
        a[i]=tmp;
        cnt[tmp]++;
    }
    bool ans=false;
    for(int i=0; i < n; i++) {
        if(cnt[a[i]] % 2 == 1) {
            ans = true;break;
        }
    }
    if(ans == false) {
        printf("Agasa\n");
    } else {
        printf("Conan\n");
    }

    return 0;
}
