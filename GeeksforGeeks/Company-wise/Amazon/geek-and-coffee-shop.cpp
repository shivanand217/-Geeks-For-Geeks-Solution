#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007

int calculate(int x, int y){
    int result = 1;
    x = x % mod;
    while(y > 0){
        if(y & 1){
            result = (result * x) % mod;
        }
        y = y>>1; // y=y/2
        x = (x * x) % mod;
    }
    return result;
}

int main() {
    int T,N,M,answer;
    cin>>T;
    while(T--){
        cin>>N>>M;
        answer = N/calculate(2,M-1);
        cout<<answer<<endl;
    }
    return 0;
}