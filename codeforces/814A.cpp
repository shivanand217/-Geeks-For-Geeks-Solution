#include<bits/stdc++.h>
using namespace std;

int a[205];
int b[205];

int n,k;

bool check_inc()
{
    int i=0;

    while(a[i] <= a[i+1] && i<n)
    {
        i++;
    }

        //cout<<i<<endl;

    if(i == n-1)
        return true;
    else
    {
        return false;
    }

}

bool comp(int x, int y)
{
    return x > y;
}

int main()
{

    scanf("%d%d", &n, &k);

    int l = -1;

    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);

        if(a[i] == 0 && l == -1)
        {
            l = i;
        }
    }

    for(int i=0; i<k; i++)
    {
        scanf("%d", &b[i]);
    }

    sort(b, b+n, comp);
    int mm=0;

    while(mm < k)
    {
        if(a[l] == 0)
        {
            a[l] = b[mm];
            mm++;
        }
        else
        {
            while(a[l] != 0)
                l++;
        }
    }

    if(check_inc())
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }

    return 0;
}
