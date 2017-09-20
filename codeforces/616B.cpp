#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e2+2;
long long restaurant_[maxn][maxn];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    long long overall_min_max = -1000000000LL;
    long long row_min;

    long long cost;

    for(int i=0; i<n ;i++)
    {
        row_min = 1000000000LL;
        for(int j=0; j<m; j++)
        {
            scanf("%lld", &cost);

            if(row_min > cost)
                row_min = cost;
        }

        if(overall_min_max < row_min)
            overall_min_max = row_min;
    }

    printf("%lld\n", overall_min_max);

return 0;

}
