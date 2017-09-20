#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define boostio std::ios::sync_with_stdio(false);cin.tie(NULL);
#define tt int n;cin>>n;while(n--)
#define ff first
#define ss second
#define pii pair<int,int>

vector<int> graph[105];

string lower(string s)
{
	for(int i=0;i<s.length();i++)
	s[i]=(char)tolower(s[i]);
	return s;
}
string upper(string s)
{
	for(int i=0;i<s.length();i++)
	s[i]=(char)toupper(s[i]);
	return s;
}
string clear_space(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==32)
        {
            s.erase(s.begin()+i);
        }
    }
}

vector<int> size_1;

int main()
{
boostio;

int n,m;
cin>>n>>m;

int a,b;

REP(i,m)
{
    cin>>a>>b;

    graph[a].pb(b);
    graph[b].pb(a);
}

stack<int> stakk;
for(int i=1;i<=n;i++)
{
    if(graph[i].size()==1)
    {
        stakk.push(i);
    }
}

int p,q;

int cnt=0;

while(!stakk.empty())
{
    int u=stakk.top();

    int q=graph[u][0];graph[u].clear();

  for(auto it=graph[q].begin();it!=graph[q].end();++it)
   {
      if(*it == u)
      {
          graph[q].erase(it);
          break;
      }
   }
stakk.pop();

if(stakk.empty()==true)
{
   for(int i=1;i<=n;i++)
   {
       if(graph[i].size()==1)
       {
           stakk.push(i);
       }
   }
   cnt++;
}

}
cout<<cnt<<endl;

return 0;

}
