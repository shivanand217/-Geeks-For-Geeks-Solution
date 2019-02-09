#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

#define maxx 66000

long long arr[maxx];

int main(){
    long long N,K,low,high,mid,current,answer=0LL;
    cin>>N>>K;

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    sort(arr, arr+N);

    for(int i=0; i<N-1; i++){
        low = i+1;
        high = N-1;
        current = -1;

        while(low <= high){
            mid = low + (high - low)/2;

            if(abs(arr[i] - arr[mid]) < K) {
                low = mid + 1;
            } else {
                current = mid;
                high = mid-1;
            }
        }

        if(current != -1){
            answer += (N - current);
        }
    }
    cout<<answer<<endl;

    return 0;
}