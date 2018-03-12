#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
long long len[mxx],G[mxx];
int main() {
    int t,n;
    scanf("%d",&t);
    while( t-- ) {
        scanf("%d",&n);
        bool fr=false, ba=false;
        for(int i=0; i<n; i++) {
            scanf("%lld",&len[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%lld",&G[i]);
        }
        int i;
        for(i=0;i<n;i++){
            if(len[i] > G[i])
                break;
        }
        if(i == n) {
            fr=true;
        }
        i = n-1;
        for( ; i >= 0; i--) {
            if(G[i] < len[n-1-i]) {
                break;
            }
        }
        if(i < 0) {
            ba = true;
        }

        if(fr==true && ba==true) {
            printf("both\n");
        } if(fr==true && ba==false) {
            printf("front\n");
        } if(fr==false && ba==true) {
            printf("back\n");
        } if(fr==false && ba==false) {
            printf("none\n");
        }
    }

    return 0;
}
