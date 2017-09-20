#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    string s1,s2;

    cin>>s1;

    cin>>s2;

    char f,s,t,h;

    f = s1[0];
    s = s1[s1.length()-1];

    t = s2[0];
    h = s2[s2.length()-1];

    if(f == '>' && h == 'v' && s=='<' && t== '^')
    {
        cout<<"YES"<<endl;

        return 0;
    }

    if(f == '<' && h == '^' && s == '>' && t == 'v')
    {
        cout<<"YES"<<endl;

        return 0;
    }

    cout<<"NO"<<endl;

    return 0;
}
