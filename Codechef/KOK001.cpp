#include<bits/stdc++.h>
#define ss second
#define ff first
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

int arr[10005];

void postorder(int index, int n) {
    if(index >= n)
        return;
    postorder(2*index+1 , n);
    postorder(2*index+2 , n);
    cout<<arr[index]<<" ";
}

int main() {

    fast;
    int t,n;
    cin>>t;

    while(t--) {

        cin>>n;
        for(int i=0; i < n; i++) {
            cin>>arr[i];
        }

        // first print given order
        int flag=1;
        cout<<arr[0]<<" ";
        int i = 1 , j = 2;

        for( ; j < n ; i = 2*i+1 , j = 2*j+2 ) {
            if(flag==1) {
                for(int k = j; k >= i; k--){
                    cout<<arr[k]<<" ";
                }
            } else {
                for(int k = i; k <= j; k++){
                    cout<<arr[k]<<" ";
                }
            }
                flag ^= 1;
        }

        j = min(n - 1 , j);

        if(flag == 1) {
            for( int k = j ; k >= i; k-- ) {
                cout<<arr[k]<<" ";
            }
        } else {
            for( int k = i; k <= j ; k++ ) {
                cout<<arr[k]<<" ";
            }
        }

        // then postorder
        cout<<endl;
        postorder(0 , n);
        cout<<endl;
    }

    return 0;
}
