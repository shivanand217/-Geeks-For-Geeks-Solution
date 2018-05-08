//
//  479A.cpp
//  
//
//  Created by apple on 08/05/18.
//

#include "479A.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    
    int i, j, m = s.length()-1;
    long long n=0LL, k=0LL, dig1=1, dig2=1;
    
    for(i = s.length()-1; i >= 0; i--) {
        if(s[i]==' ') {
            j = i+1;
            i -= 1;
            break;
        }
    }
    
    while(m >= j) {
        k += (s[m--]-'0')*dig1;
        dig1 *= 10;
    }
    
    while(i >= 0) {
        n += (s[i--]-'0')*dig2;
        dig2 *= 10;
    }
    
    long long last;
    
    while(k) {
        if(n == 0) {
            break;
        }
        last = n%10;
        
        if(last == 0){
            n /= 10;
        } else {
            n -= 1;
        }
        k -= 1;
    }
    
    cout<<n<<endl;
    
    return 0;
}
