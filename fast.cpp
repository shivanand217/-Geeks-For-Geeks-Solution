#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int fast_pow(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}

int calculate(string l)
{
    int num=0;
    int m=0;

int tmp;
    for(int i=l.length()-1; i>=0; i--)
    {
        if(l[i] == '1'){
        tmp = fast_pow(2,m);
        cout<<tmp<<" ";
        num+=tmp;
    }
m++;
    }
    cout<<endl;
    return num;
}

int main()
{
    string s;
    cin>>s;

int j=1;

while(j!=s.length()-1)
{

string p="";
for(int i=1; i<=7; i++)
{
p+=s[i];
}

}

    int k = calculate(p);
    cout<<char(k);

    p="";

    for(int i=8; i < s.length()-1; i++)
    {
        if(i == s.length()-2)
        {
            p+=s[i];
            k = calculate(p);
            cout<<char(k);break;
        }
        if(i % 8 == 0)
        {
            if(i != 8)
            {
        //    else{
            p = "";
            k = calculate(p);
            cout<<char(k);
            }
        }

        if(i % 8 != 0)
        {
            p += s[i];
        }
    }


    cout<<endl;
    return 0;
}
