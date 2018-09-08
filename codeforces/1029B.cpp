#include<bits/stdc++.h>
using namespace std;

int mx = 2e5+10;
int arr[mx];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int i=0,j=1;
    int ans=1;

    while(i < n-1) {
        if(arr[i]*2 < arr[i+1]){
            i++;
        } else {

        }
    }

    return 0;
}
