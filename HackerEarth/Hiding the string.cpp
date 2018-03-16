#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    string s,a,b;

    while(t--) {
        cin>>s>>a>>b;
        int len1=a.length();
        int len2=b.length();
        int i;
        int indx1 = -1, indx2 = -1;
        for(i=0; i <= (s.length() - a.length()); i++) {
            if(s.substr(i, len1) == a) {
                indx1 = i;
                i= i+len1;
                break;
            }
        }

        for(int j=i; j <= (s.length()-len2); j++) {
            if(s.substr(j, len2) == b){
                indx2 = j;
                break;
            }
        }

        if(indx1 != -1 && indx2 != -1){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
