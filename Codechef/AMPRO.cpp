#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    vector<string> ans;
    int i=0;
    string s1 = "";
    string temp;

    while(i < s.length()) {
        if( s[i] == ' ' ) {
            char p = s1[0];
            temp = "";
            temp += p;
            temp += '.';
            temp[0] = (char)toupper(temp[0]);
            ans.push_back(temp);
            s1 = "";
        } else {
            s1 += s[i];
        }
        i++;

    }

    s1[0] = (char)toupper(s1[0]);
    ans.push_back(s1);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }   cout<<endl;

    return 0;
}
