#include<bits/stdc++.h>
using namespace std;

string s;
map<string,int> mapp;
int main()
{

    int n;
    cin>>n;

    stack<string> sp;

    for(int i=0;i<n;i++)
    {
        cin>>s;

    sp.push(s);
    }

    while(!sp.empty())
    {
        string tmp=sp.top();sp.pop();
int k=mapp[tmp];

if(k!=1)
{
    cout<<tmp<<endl;
    mapp[tmp]++;
}
    }

    return 0;
}
