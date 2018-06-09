#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

#define fast std::ios::sync_with_stdio(false)

const int mx = 1e4+10;
int t,N,A,B,tmp;
int arr[mx];
double ans,a,b;

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    cout.precision(10);

    while(t--) {
        memset(arr, 0, sizeof(arr));
        cin>>N>>A>>B;

        for(int i=0; i < N; i++) {
            cin>>tmp;
            arr[tmp]++;
        }

        a = ((double) arr[A])*1.0;
        b = ((double) arr[B])*1.0;

        ans = a/((double) N)*1.0;
        ans *= b/((double) N)*1.0;

        cout<<fixed<<ans<<endl;
    }

    return 0;
}
