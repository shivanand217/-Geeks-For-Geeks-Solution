#include<iostream>
using namespace std;

#define maxx 1005

int arr[maxx];

int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int j=1;
    int ans=0;

    while(j<n){
        if(arr[j] == 0){
            if(arr[j-1]==1&&arr[j+1]==1){
                arr[j+1]=0;
                ans++;    
            }
        } j++;
    }
    cout<<ans<<endl;

    return 0;
}