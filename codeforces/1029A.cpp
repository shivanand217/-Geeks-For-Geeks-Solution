#include<bits/stdc++.h>
using namespace std;

string s,dummy;
int n,k;

int main() {
    cin>>n>>k;
    cin>>s;

    int i=1,p,target=-1,j;
    int len=INT_MAX;

    while(i < s.length()) {
        if(s[0] == s[i]) {
            p = 0;
            j = i;
            i++;
            while(1) {
                if(j == s.length()){
                    break;
                }
                if(s[p] == s[j]) {
                    p++;j++;
                } else {
                    break;
                }
            }
            if(j == s.length()) {
                /** If the current length is greater than previous length **/
                if(len > (s.length() - p)) {
                    len = (s.length() - p);
                    target = p;
                }
            } else {
                /** if unmatch takes place do nothing **/
            }
        } else {
            i++;
        }
    }

    if(target == -1) {
        dummy=s;
        k-=1;
        while(k > 0){
            s+=dummy;
            k-=1;
        }
    } else {
        dummy=s.substr(target,(s.length()-target));
        k-=1;
        while(k > 0) {
            s+=dummy;
            k-=1;
        }
    }

    cout<<s<<endl;

    return 0;
}
