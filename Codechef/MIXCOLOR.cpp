#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
long long ar[mxx];

int main() {
    int t,n;
    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&ar[i]);
        }
        sort(ar,ar+n);
        int ans=0;
        int curr= ar[0];
        for(int i=1;i<n;i++){
            if(curr == ar[i])
                ans++;
            else {
                curr=ar[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
