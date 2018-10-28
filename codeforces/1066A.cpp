#include<iostream>
using namespace std;

// g++ -std=c++0x

int main(){
    int t;
    int L,l,r,v,x1,x2,tmp1,tmp2;
    int sum=0;
    cin>>t;

    while(t--) {
        sum=0; x1=0; x2=0;
        cin>>L>>v>>l>>r;
        if(l != 1){
            tmp1=(l-1)/v;
            tmp2=(1)/v;
            x1=(tmp1-tmp2);
            if(1%v==0){
                x1++;
            }
        } 
        if(r != L){
            tmp1=(L/v);
            tmp2=((r+1)/v);
            x2=(tmp1-tmp2);
            if((r+1)%v==0){
                x2++;
            }
        }
        sum+=(x1+x2);
        cout<<sum<<endl;
    }

    return 0;
}