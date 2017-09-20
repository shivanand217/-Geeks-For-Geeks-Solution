#include<bits/stdc++.h>
using namespace std;

int k,a,b;
int main()
{
    cin>>k>>a>>b;

    if(a<k && b<k)
        {cout<<-1<<endl;return 0;}

        if((a<k && b%k!=0) || (b<k && a%k!=0))
            cout<<-1<<endl;
        else
        {
            cout<<(a/k+b/k)<<endl;
        }

    return 0;
}
