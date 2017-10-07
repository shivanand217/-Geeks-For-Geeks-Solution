#include<bits/stdc++.h>
using namespace std;

int main() {
       long long a,b,f,s;
       cin>>a>>b;
       long long p,q;
       long long pro=1LL;
       if(b<a){
              cout<<"0"<<endl;
       } else if (b==a){
              cout<<"1"<<endl;
       } else {
              p=(a%10);
              q=(b%10);
              if(q == 0){
                     cout<<"0"<<endl;
              } else {
                     if(b-a >= 10){
                            cout<<"0"<<endl;
                     } else {
                            f=a+1;
                            pro=1LL;
                            while(f<=b){
                                  long long k=(f%10);
                                  pro=pro*k;
                                  f++;
                            }
                            long long ans=(pro%10);
                            cout<<ans<<endl;
                     }
              }
       }
       return 0;
}
