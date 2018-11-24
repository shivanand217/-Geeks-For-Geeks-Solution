#include<iostream>
using namespace std;

int main(){
    int n,S,ans,tmp,k;
    cin>>n>>S;

    if(S <= n){
        //edge case
        ans=1;
    } else {
        k = S/2;
        
        if(k > n){
            tmp = S/n;

            if(S % n == 0){
                ans = tmp;
            } else {
                ans = tmp+1;
            }
        } else if (k == n) {
            if(S % n == 0){
                ans = 2;
            } else {
                ans = 3;
            }
        } else {
            ans=2;
        }
    }
    cout<<ans<<endl;

    return 0;
}