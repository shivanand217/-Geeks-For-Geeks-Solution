#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

const int maxn = 1e5+2;
ll arr[maxn];
int n;
ll a,b,c;

bool ans=false;

int main()
{
    read(n)

    for(int i=0; i<n; i++)
    {
        read(arr[i])
    }

    sort(arr,arr+n);

    if(n == 3)
    {
        a=arr[0];
        b=arr[1];
        c=arr[2];

        if(a+b > c && b+c > a && c+a > b)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

            ans=true;
    }
    if(ans == false)
    {
        for(int i=0; i<n-2; i++)
        {
            a=arr[i];
            b=arr[i+1];
            c=arr[i+2];

            if(a+b > c && b+c > a && c+a > b)
                {cout<<"YES"<<endl;ans=true;break;}

            //    cout<<"NO"<<endl;
        }
        if(ans == false)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
