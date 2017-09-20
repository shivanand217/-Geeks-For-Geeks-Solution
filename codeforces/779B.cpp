#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

ull fast_pow(ull x,ull y)
{
    ull res=1;
    while(y > 0)
    {
        if(y % 2 == 1)
        {
            res = (res*x);
        }

        x = (x*x);
        y/=2;
    }
    return res;
}

int main()
{
    ull n;
    ull a;

    ull k;
    cin>>n>>k;
    a = fast_pow(10,k);

    int cnt;

    int cnt_0 =0 ;
    int cnt_diff=0;

    ull tmp = n;

    if(n == 0)
    {
        cout<<0<<endl;
        return 0;
    }

    if(n < a)
    {
        cnt =0 ;
        while(n > 0)
        {
            n/=10;
            cnt++;
        }
        cout<<cnt-1<<endl;return 0;
    }
    else
    {
        while(n > 0)
        {
            if(n % 10 != 0 && n/10 != 0)
            {
                cnt_diff++;
            }
            if(n% 10 == 0)
            {
                cnt_0++;
            }
            if(cnt_0 == k)
            {
                cout<<cnt_diff<<endl;return 0;
            }
            n/=10;
        }

        if(cnt_0 < k)
        {
            cnt = 0;

            while(tmp > 0 )
            {
                tmp/=10;
                cnt++;
            }
            cout<<cnt-1<<endl;
        }
    }
    return 0;
}
