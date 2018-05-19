#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false)
using namespace std;
string s;
int n;
int main() {
    fast;
    cin.tie(NULL);
    cin>>n;
    cin>>s;
    int ans=0;
    int i=0,cnt=0;
    while(i < s.length()) {
        if(i == s.length()-1 || i == s.length()-2){
            break;
        }
        if(s[i]=='x' && s[i+1]=='x' && s[i+2]=='x'){
            cnt=0;
            while(s[i] == 'x') {
                cnt++;
                i++;
            }
            ans+=(cnt-2);
            cnt = 0;
        } else {
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
