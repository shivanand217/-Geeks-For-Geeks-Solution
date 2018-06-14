#include<bits/stdc++.h>
using namespace std;
#define fast std::ios::sync_with_stdio(false)

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);
    string s;

    int m,n;
    cin>>n>>m;
    cin>>s;

    int i=0,j=m;
    if(s.length() == 1 || (n == m)) {
        cout<<"No"<<endl;
        return 0;
    }
    if(j >= n) {
        for(int k=0; k < s.length(); k++) {
            if(s[k] == '.') {
                s[k] = '0';
            }
        }
        cout<<s<<endl;
        return 0;
    }

    bool ans = true;
    int old = j;

    while(i < s.length()-m) {
        if(j >= n) {
            if(ans == true) {
                cout<<"No"<<endl;
                return 0;
            } else break;
        }
        if(s[i] != s[j]) {
            ans=false;
            if(s[j]=='.'){
                if(s[i]=='1') {
                    s[j]='0';
                } else if(s[i]=='0'){
                    s[j]='1';
                }
            }
            if(s[i]=='.') {
                if(s[j]=='1'){
                    s[i]='0';
                } else if(s[j]=='0'){
                    s[i]='1';
                }
            }
        } else {
            if(s[i]=='.'&&s[j]=='.'){
                s[i]='0';s[j]='1';
                ans=false;
            }
        }
        //cout<<i<<" "<<j<<endl;
        //cout<<s[i]<<" "<<s[j]<<endl;
        i++; j++;
        if(j >= n) {
            if(ans == true) {
                cout<<"No"<<endl;
                return 0;
            } else break;
        }
    }

    while(i < s.length()) {
        if(s[i]=='.')
            s[i]='1';
        i++;
    }
    cout<<s<<endl;

    return 0;
}
