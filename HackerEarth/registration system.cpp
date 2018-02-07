#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string,int>used;
    map<string,int>cache;
    int n,v;
    cin>>n;
    string user;
    for(int i=0; i<n; i++) {
        cin>>user;
        v = cache[user];
        string temp = user;
        while( used[user] == 1 ) {
            user = temp + to_string(v);
            v++;
        }
        cache[temp] = v;
        used[user] = 1;
        cout<<user<<"\n";
    }
    return 0;
}
