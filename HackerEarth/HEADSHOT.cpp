#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long ar[100005];

int main() {
    ar[1]=ar[2]=1;
    
    for(int i=3;i<=100000;i++){
        ar[i]=((ar[i-1]%mod)+(ar[i-2]%mod))%mod;
    }

    int n;
    cin>>n;
    cout<<ar[n];
    return 0;
}