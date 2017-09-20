#include<bits/stdc++.h>
using namespace std;
int h[102];

int main()
{
    int n,m,k;
    scanf("%d %d %d", &n ,&m, &k);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &h[i]);
    }

    int i,j;
    int f=1000000000LL,s=1000000000LL;
    int ans;

    if(m == 1)
    {
        i=2;

        while(i<=n)
        {
            if(h[i] != 0)
            {
                if(h[i] <= k)
                {
                    f = i;break;
                }
            }
            i++;
        }
        cout<<(10*abs(m-f))<<endl;
    }
    else if(m==n)
    {
        i=m-1;
        while(i>=0)
        {
            if(h[i] != 0)
            {
                if(h[i]<=k)
                {
                    f = i;break;
                }
            }
            i--;
        }
        cout<<(10*abs(m-f))<<endl;
    }
    else
    {
        i = m-1;j = i+1;
        while(i>=0)
        {
            if(h[i] != 0)
            {
                if(h[i] <= k)
                {
                    f = i;break;
                }
            }
            i--;
        }

        while(j<=n)
        {
            if(h[j] != 0)
            {
                if(h[j] <= k)
                {
                    s = j;break;
                }
            }
            j++;
        }
        ans = min(abs(m-f),abs(m-s));

        cout<<(10*ans)<<endl;
    }


    return 0;
}
