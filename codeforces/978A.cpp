#include<bits/stdc++.h>
using namespace std;

int mark[2000];

int main() {
    int n;
    scanf("%d", &n);
    memset(mark, 0, sizeof(mark));
    int *ar = (int *)malloc(n*(sizeof(int)));
    int total=0;
    for(int i=0; i < n; i++) {
        scanf("%d",&ar[i]);
        if(mark[ar[i]] == 0)
            total++;
        mark[ar[i]]++;
    }
    printf("%d\n",total);
    for(int i =0;i<n;i++) {
        if(mark[ar[i]] == 1){
            printf("%d ",ar[i]);
            mark[ar[i]]--;
        } else {
            mark[ar[i]]--;
        }
    }
    return 0;
}
