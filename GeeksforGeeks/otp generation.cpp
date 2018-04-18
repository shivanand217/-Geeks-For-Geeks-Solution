#include<bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));

    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    string otp;

    int len = 6;

    for(int i=1; i<=len; i++)
    {
        otp.push_back(s[rand()%s.length()]);
    }

    cout<<otp<<endl;
    return 0;
}
