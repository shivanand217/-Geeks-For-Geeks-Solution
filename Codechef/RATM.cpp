#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    bool pal= true;
    int i=0, j=s.length()-1;
    while(i < j) {
        if(s[i] != s[j]){
            pal = false;
            break;
        }
        i++;
        j--;
    }
    return pal;
}

int main() {
    int t;
    cin>>t;
    int n;
    string s;
    while(t--) {
        cin>>n;
        cin>>s;
        if(check(s)) {
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
        }
    }

    return 0;
}
