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
    int len = s.length();
    while( i < len ) {
        if(i == len-1 || i == len-2){
            break;
        }
        if(s[i]=='x' && s[i+1]=='x' && s[i+2]=='x'){
            cnt=0;
            while(s[i] == 'x') {
                cnt++;
                i++;
                if(i == len){
                    break;
                }
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
