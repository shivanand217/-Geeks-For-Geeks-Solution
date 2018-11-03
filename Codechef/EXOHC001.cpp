#include<iostream>
using namespace std;

int main() {
    int test;
    cin>>test;

    int year;
    while(test--){
        cin>>year;

        if(year%4 == 0){
            if(year%100==0){
                if(year%400==0){
                    cout<<"Yes"<<endl;
                } else {
                    cout<<"No"<<endl;
                }
            } else {
                cout<<"Yes"<<endl;
            }
        } else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}