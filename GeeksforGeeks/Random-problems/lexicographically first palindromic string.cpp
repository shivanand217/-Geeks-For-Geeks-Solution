#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    cin>>s;
    for(int i=0; i < s.length(); i++){
        cnt[s[i]-'a']++;
    }
    int odd_=0;
    int indx=-1;
    for(int i=0; i < 26; i++){
        if(cnt[i]%2 == 1)
            odd_++,indx=s[i]-'a';
    }
    cout<<indx<<endl;
    if(odd_ > 1 ) {
        return 0;
    }
    string ans="",odd="";
    if(odd_== 1) {
        int c = cnt[indx];
        while(c>0){
            odd+=(indx+'a');
            c--;
        }
    }
    cout<<odd<<endl;
    return 0;
}
