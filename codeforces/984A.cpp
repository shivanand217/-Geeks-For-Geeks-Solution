#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)
int n,index;

const int mxn = 10005;
int arr[mxn];

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+n);

    if(n%2 == 1) {
        index = n/2;
    } else {
        index = n/2 - 1;
    }

    cout<<arr[index]<<endl;
    return 0;
}
