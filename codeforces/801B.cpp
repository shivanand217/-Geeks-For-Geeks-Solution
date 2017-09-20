#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    string c="";

    for(int i=0; i<s1.length(); i++)
    {

        if(s2[i] > s1[i])
        {
            cout<<-1<<endl;return 0;
        }

        if(s2[i] == s1[i])
        {
            c+='z';
        }

        if(s2[i] < s1[i])
        {
            c+=s2[i];
        }

    }

    cout<<c<<endl;
    return 0;
}
