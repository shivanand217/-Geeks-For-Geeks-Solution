#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin>>n;

    if(n == 0) {
        cout<<"0"<<endl;
    } else {
        if((n+1)%2 == 0) {
            cout<<((n+1)/2)<<endl;
        } else {
            cout<<(n+1)<<endl;
        }
    }

    return 0;
}
