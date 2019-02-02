#include <iostream>
using namespace std;

int main() {
    int n,first,second;
    cin>>n;
    int winner,lead=0,temp,sum1=0,sum2=0;

    for(int i=0; i<n; i++){
        cin>>first>>second;
        sum1+=first;
        sum2+=second;
        if(first > second){
            temp = first - second;
            if(lead < temp){
                lead=temp;
                winner=1;
            }
        } else {
            temp = first - second;
            if(lead < temp){
                lead=temp;
                winner=2;
            }
        }
    }

    cout<<winner<<" "<<lead<<endl;

    return 0;
}