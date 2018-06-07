#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)
int k,n,s,p;

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>k>>n>>s>>p;

    int sheets,packs,total_sheets;

    if(n%s == 0) {
        sheets = n/s;
    } else {
        sheets = n/s + 1;
    }

    total_sheets=k*sheets;

    if(total_sheets%p == 0) {
        packs=total_sheets/p;
    } else {
        packs=total_sheets/p+1;
    }

    cout<<packs<<endl;
    return 0;
}
