#include<bits/stdc++.h>
using namespace std;

char ch[2005];
char ans[2005];
int n;

int main()
{
    cin>>n;
for (int i=1;i<=n; i++)
{
    cin>>ch[i];
}

    if(n%2!=0)
    {
        int p=(n/2)+1;
        int k=n/2;

        int m=1;
        while(m<=n)
        {
            if(m%2!=0)
                {ans[p]=ch[m];p++;}
            else
                {ans[k]=ch[m];k--;}
            m++;
        }
    }
    else
    {
        int p=n/2;
        int k=n/2+1;

        int m=1;
        while(m<=n)
        {
            if(m%2!=0)
                {ans[p]=ch[m];p--;}
            else
                {ans[k]=ch[m];k++;}
            m++;
        }
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i];

return 0;
}
