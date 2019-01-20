#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s;
    getline(cin,s);

    int hash[26],count=0;
    memset(hash, 0, sizeof(hash));

    for(int i=0; i<s.length(); i++){
        if(s[i] == '{' || s[i] == '}' || s[i] == ' ' || s[i] == ',' ){
            continue;
        } else {
            hash[s[i]-'a']=1;
        }
    }

    for(int i=0; i<26; i++){
        if(hash[i]==1){
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}