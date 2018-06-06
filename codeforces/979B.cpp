#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)

int hash1[256],hash2[256],hash3[256];
string s1,s2,s3;
int n, a=0, b=0, c=0;

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;

    cin>>s1>>s2>>s3;
    for(int i=0; i < 256; i++) {
        hash1[i]=0;hash2[i]=0;hash3[i]=0;
    }
    for(int i=0; i < s1.length(); i++) {
        a=max(a, ++hash1[s1[i]]);
    }
    for(int i=0; i < s2.length(); i++) {
        b=max(b, ++hash2[s2[i]]);
    }
    for(int i=0; i < s3.length(); i++) {
        c=max(c, ++hash3[s3[i]]);
    }

    if(n == 1 && a==(int)s1.length())
        s1.pop_back();
    if(n == 1 && b==(int)s2.length())
        s2.pop_back();
    if(n == 1 && c==(int)s3.length())
        s3.pop_back();

    a = min((a+n), (int)s1.length());
    b = min((b+n), (int)s2.length());
    c = min((c+n), (int)s3.length());

    if(a > b && a > c){
        cout<<"Kuro"<<endl;
        return 0;
    }
    if(b > a && b > c){
        cout<<"Shiro"<<endl;
        return 0;
    }
    if(c > a && c > b){
        cout<<"Katie"<<endl;
        return 0;
    }

    cout<<"Draw"<<endl;

    return 0;
}
