#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;

    int i = 0;
    bool ans = false;
    if(s.length() < 3) {
        cout<<"No"<<endl;
        return 0;
    }
    while( i < s.length() - 2 ) {
        if(s[i]!=s[i+1] && s[i+1]!= s[i+2] && s[i]!=s[i+2]
           && s[i]!='.' && s[i+1]!='.' && s[i+2]!='.') {
            ans=true;
            break;
        }
        i++;
    }
    if(ans == false) {
        cout<<"No"<<endl;
    } else {
        cout<<"Yes"<<endl;
    }

    return 0;
}
