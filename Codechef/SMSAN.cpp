#include<bits/stdc++.h>
using namespace std;
string s;

int main() {
    getline(cin,s);
    int i=0;
    string s1="love",s2="babe",s3="sweety",s4="life";
    int cnt1=0,cnt2=0;

    while(i < s.length()) {
        if( s.substr(i, s1.length()) == s1 ){
            cnt1++;
        }
        if( s.substr(i, s2.length()) == s2 ){
            cnt1++;
        }
        if( s.substr(i, s3.length()) == s3 ){
            cnt1++;
        }
        if( s.substr(i, s4.length()) == s4 ){
            cnt1++;
        }
        if( s[i] == ' '){
            cnt2++;
        }
        i++;
    }
    cnt2++;
    int g = __gcd(cnt1,cnt2);
    cnt1 /= g;
    cnt2 /= g;

    cout<<cnt1<<"/"<<cnt2<<endl;

    return 0;
}
