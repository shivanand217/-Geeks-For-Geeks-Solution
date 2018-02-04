#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    float ans,m;

    cin>>n>>m;
    float a,b,k;

    for(int i = 0; i < n; i++) {
        cin>>a>>b;
        k = ((1.0 * a)/(b * 1.0))*(m * 1.0);
        if(i == 0) {
            ans = k;
        } else {
            if(ans > k) {
                ans = k;
            }
        }
    }

    printf("%.8f\n", ans);

    return 0;
}
