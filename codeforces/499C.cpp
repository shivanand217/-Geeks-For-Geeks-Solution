#include<bits/stdc++.h>
#define ll long long
#define si(x) scanf("%d",&x)
using namespace std;

int main(){

    int x , y;
    si(x); si(y);

    int x2 , y2;
    si(x2); si(y2);

    int n, a, b, c;
    si(n);

    ll sign1, sign2;
    int ans=0;

    /** cheking signs of either both points are on same side of line **/

    for(int i=0; i<n; i++){
        si(a); si(b); si(c);

        sign1 = (ll)a*x + (ll)b*y + (ll)c;
        sign2 = (ll)a*x2 + (ll)b*y2 + (ll)c;

        if( (sign1 < 0 && sign2 > 0) || (sign1 > 0 && sign2 < 0) ){
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}
