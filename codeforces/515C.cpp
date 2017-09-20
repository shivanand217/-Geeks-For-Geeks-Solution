#include<bits/stdc++.h>
using namespace std;
bool comp(char x,char y){
    return x>y;
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,string>un;
    un['2']="2";un['3']="3";un['4']="322";un['5']="5";
    un['6']="53";un['7']="7";un['8']="7222";un['9']="7332";
    string ans="";
    for(int i=0;i<s.length();i++)
        ans+=un[s[i]];
    sort(ans.begin(),ans.end(),comp);
    cout<<ans;
	return 0;
}
