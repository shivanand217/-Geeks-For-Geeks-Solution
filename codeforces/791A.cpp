#include<bits/stdc++.h>
using namespace std;

int main(){
       int a,b;
       
       cin>>a>>b;
       
       int y=0;
       if(a>b)
       {
              cout<<0<<endl;
       }
       else
       {
              while(a<=b){
                     a*=3;b*=2;
                     y++;
              }
              
              cout<<y<<endl;
       }
       return 0;
}
