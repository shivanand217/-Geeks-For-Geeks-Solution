//
//  479B.cpp
//  
//
//  Created by apple on 08/05/18.
//

#include "479B.hpp"

#include<bits/stdc++.h>
using namespace std;

map<string,int> mpp;

int main() {
    int n;
    string s,p;
    
    cin>>n>>s;
    
    for(int i=0; i<s.length(); i++) {
        
        if(i == s.length() - 1) {
            break;
        }
        p = s.substr(i,2);
        un[p]++;
    }
    
    string ans="";
    int mx = 0;
    
    for(auto it= mpp.begin(); it != mpp.end(); ++it) {
        if(it->second > mx){
            mx = it->second;
            ans = it->first;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
