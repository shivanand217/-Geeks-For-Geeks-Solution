#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;

    int pearl=0,dash=0;

    for(int i=0; i < s.length(); i++) {
        if(s[i] == '-') {
            dash++;
        } else {
            pearl++;
        }
    }

    if(pearl == 0) {
        cout<<"YES"<<endl;
        return 0;
    }

    if(dash%pearl == 0) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}
