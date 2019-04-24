#include <bits/stdc++.h>
using namespace std;
int n,i;
string s;
int main(){
	for(cin>>n>>s,i=1;i<n&&s[i]>=s[i-1];i++);
	i==n?cout<<"NO":cout<<"YES\n"<<i<<" "<<i+1;
}