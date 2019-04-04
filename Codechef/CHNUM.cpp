#include<iostream>
using namespace std;

int main(){
    int t,n,pos_count,neg_count,tmp;
    cin>>t;

    while(t--) {
        pos_count=0;
        neg_count=0;
        cin>>n;
        for(int i=0; i<n; i++){ 
            cin>>tmp;
            if(tmp >= 0){
                pos_count+=1;
            } else {
                neg_count+=1;
            }
        }
        if(pos_count == 0){
            cout<<neg_count<<" "<<neg_count<<endl;
            continue;
        }
        if(neg_count == 0){
            cout<<pos_count<<" "<<pos_count<<endl;
            continue;
        }
        cout<<max(pos_count,neg_count)<<" "<<min(pos_count,neg_count)<<endl;
    }

    return 0;
}