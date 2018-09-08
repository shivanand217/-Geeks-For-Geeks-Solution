#include<bits/stdc++.h>
using namespace std;
int N,X,S,A,B,current_box;
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>N>>X>>S;
        current_box=X;
        for(int i=0;i<S;i++) {
            cin>>A>>B;
            if(A==current_box){
                current_box=B;
            }else if(B==current_box){
                current_box=A;
            }
        }
        cout<<current_box<<endl;
    }
    return 0;
}
