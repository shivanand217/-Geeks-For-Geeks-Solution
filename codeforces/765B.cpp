#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int curr=97;

    for(int i=0; i<s.length(); i++)
    {
        if(int(s[i]) == curr)
            curr++;
        else
        {
            if(int(s[i]) > curr)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;
    return 0;
}
