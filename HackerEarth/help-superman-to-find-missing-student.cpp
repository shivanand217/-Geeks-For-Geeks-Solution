#include<bits/stdc++.h>
#define mx 30000
using namespace std;
int en[mx];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&en[i]);
        }
        sort(en,en+n);
        int ans;
        for(int i=1;i<n;i++) {
            if(en[i] != en[i-1]+1){
                ans=en[i]-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
