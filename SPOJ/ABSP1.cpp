#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;
#define maxx 10001

ll ar[maxx];
ll sumArray[maxx];

int main() {

    int t, n;
    scanf("%d", &t);

    while(t--)
    {
        long long int totalSum = 0;
        long long int previousSum = 0;
        scanf("%d", &n);
        scanf("%lld", &ar[0]);

        sumArray[0] = 0;

        for(int i = 1;i < n; ++i)
        {
            scanf("%lld", &ar[i]);
            long long int temp = previousSum + (i-1)*(ar[i] - ar[i-1]) + ar[i] - ar[i-1];
            sumArray[i] = temp;
            previousSum = temp;
            totalSum += temp;
        }
        printf("%lld\n", totalSum);
    }

    return 0;
}
