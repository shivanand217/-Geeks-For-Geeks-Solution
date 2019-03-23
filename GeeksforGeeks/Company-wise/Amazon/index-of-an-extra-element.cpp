#include<iostream>
using namespace std;

#define mxx 200

int arr1[mxx],arr2[mxx];

int main(){
    int t,n;
    cin>>t;
    int index,j,smallest;

    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr1[i];
        }
        for(int i=0; i<n-1; i++){
            cin>>arr2[i];
        }
        j=0;
        smallest = n-1;
        while(j < smallest){
            // at the last index of the smallest array
            if(j == smallest-1){
                // no mismatch
                if(arr1[j] == arr2[j]){
                    index=j+1;
                } else {
                    index=j;
                }
                break;
            }
            if(arr1[j] != arr2[j]){
                index=j;
                break;
            }
            j+=1;
        }
        cout<<index<<endl;
    }

    return 0;
}