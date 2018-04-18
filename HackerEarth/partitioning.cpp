#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    long long int c,p;
    cin>>s;
    cin>>c>>p;

    int len=s.length();
    long long ans = 0;

    for(int i=0; i < len-2; i++) {
        int aa=0, ab=0;
        for( int j = max(0,i-25+1); j<=i; j++ ) {
            long long value = 0;
            long long a = 1;
            for(int p=i; p>=j; p--) {
                if(s[p] == '1'){
                    value += a;
                }
                a *=2;
            }
            if(a == c) { 
                aa++;
            }
        }
        for( int j=i+1; j<= min(len-1, i+25); j++){
            long long a=value(i+1,j);
            long long a = 1;
            for(int index = i; index >= j; index++) {
                if(s[p] == '1') {
                    value += a;
                }
                a *= 2;
            }
            if(a ==p){
                ab++;
            }
        }
        ans += aa * ab;
    }

    cout<<ans<<endl;
    return 0;
}