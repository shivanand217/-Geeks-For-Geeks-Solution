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

int ae[102];
int table[102][102];

int sum(int a,int b) {
    int s=0;
    for(int i=a; i <= b; i++) {
        s = (s + ae[i])%100;
    }
    return s;
}

int Solve_dp(int a,int b) {
    if(table[a][b] != -1) {
        return table[a][b];
    }

    if(a == b)
        return 0;

    int value = table[a][b];
    for(int k=a; k+1 <= b; k++) {
        /** split into two subsets one subset contains ae[a...k] and other contain ae[k+1...b] **/
        int temp = Solve_dp(a,k) + Solve_dp(k+1,b) + sum(a,k) * sum(k+1,b);
        if(value == -1 || temp < value)
            value = temp;
    }

    return ( table[a][b] = value );
}

int main() {

    int n;
    while(cin>>n) {
        for(int i=1; i<=n; i++) {
            cin>>ae[i];
        }
        memset(table, -1, sizeof(table));
        cout<<Solve_dp(1,n)<<endl;
    }

    return 0;
}
