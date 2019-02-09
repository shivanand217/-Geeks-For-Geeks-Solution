#include <iostream>
#include <cstdlib>
using namespace std;

long long calculate(long long y, long long x){
    cout<<x<<" "<<y<<endl;
    if(y==0){
        return 1LL;
    } else if (y == 1) {
        return x;
    }

    long long num = calculate(y/2LL, x);
    if(y%2 == 0)
        return ((num % 41LL) * (num % 41LL)) % 41LL;

    if(y%2 == 1)
        return ((num % 41LL) * (num % 41LL) * x) % 41LL;
}

int main(){
    long long y = 98765432123456789;
    //y = 10;
    cout<<y<<endl;
    long long answer = calculate(y, 14LL);
    cout<<answer<<endl;

    return 0;
}