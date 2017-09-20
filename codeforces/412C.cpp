#include<bits/stdc++.h>
using namespace std;

#define sz(c) (c).size()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define boostio std::ios::sync_with_stdio(false);cin.tie(NULL);
#define tt int n;cin>>n;while(n--)
#define ff first
#define ss second
#define pii pair<int,int>

int main()
{
boostio;

string result;
string s;

int n;
cin>>n;

if(n==1)
{
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='?')
            s[i]='a';
    }
    cout<<s<<endl;
    return 0;
}

map<int,char> mapp;
for(int i=0;i<n;i++)
{
cin>>s;

if(i==0)
{
for(int j=0;j<s.length();j++)
{
   mapp.insert(mp(j+1,s[j]));
}

}
else
{
    for(int j=0;j<s.length();j++)
    {
       if(s[j]=='?')
        continue;
       else if(s[j]!='?')
       {
           if(mapp[j+1]=='?')
           {
               mapp[j+1]=s[j];
           }
           else if(mapp[j+1]!=s[j])
           {
               mapp[j+1]='!';
           }
       }
    }
}

}

int i=1;
for(auto it=mapp.begin();it!=mapp.end();++it)
{
    if(mapp[i]=='!')
        result+='?';
    else if(mapp[i]=='?')
        result+='x';
    else
       result+=mapp[i];
       i++;

}

cout<<result<<endl;
return 0;
}
