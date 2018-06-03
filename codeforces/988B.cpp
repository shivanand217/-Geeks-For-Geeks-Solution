#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)
string s,test;
vector<string> v;
int n;

bool compare(string s1,string s2) {
    return s1.length() < s2.length();
}

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>s;
        v.push_back(s);
    }

    sort(v.begin(),v.end(),compare);
    int len;
    bool ok, ans=true;

    for(int i=0; i < v.size()-1; i++) {
        len = v[i].length();
        ok = false;
        for(int j=0; j <= v[i+1].length()-len; j++) {
            test=v[i+1].substr(j,len);
            if(test == v[i]){
                ok=true;
                break;
            }
        }
        if(ok == false) {
            ans=false;
            break;
        }
    }

    if(ans == false) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        for(auto it =v.begin(); it!= v.end(); ++it) {
            cout<<*it<<endl;
        }
    }

    return 0;
}
