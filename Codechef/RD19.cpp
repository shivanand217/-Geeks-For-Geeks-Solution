#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;

#define fast std::ios::sync_with_stdio(false)
int t,n,gcd,tmp;

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;

    while(t--) {
        cin>>n;

        for(int i=0; i < n; i++) {
            cin>>tmp;
            if(i == 0) {
                gcd = tmp;
            } else {
                gcd = __gcd(gcd, tmp);
            }
        }

        if(gcd == 1) {
            cout<<"0"<<endl;
        } else {
            cout<<"-1"<<endl;
        }
    }

    return 0;
}
