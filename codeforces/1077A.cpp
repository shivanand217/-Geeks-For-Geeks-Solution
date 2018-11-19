#include<iostream>
using namespace std;

int main(){
    int t;
    long long a,b,k,one,two,ans;
    
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        if(k%2 == 0){
            one = (k/2)*a;
            two = (k/2)*b;
            ans = one - two;
        } else {
            one = (k/2 + 1)*a;
            two = (k/2)*b;
            ans = one - two;
        }
        cout<<ans<<endl;
    }

    return 0;
}