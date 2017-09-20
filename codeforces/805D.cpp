#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int k=0;
    int c=0;

    for(int i=s.length()-1; i>=0; i--)
    {
        if(s[i] == 'b')
        {
            c++;
        }
        else
        {
            k +=c;
            c*=2;
            k%=1000000007;
            c%=1000000007;
        }
    }

    cout<<k<<endl;
    return 0;
}
