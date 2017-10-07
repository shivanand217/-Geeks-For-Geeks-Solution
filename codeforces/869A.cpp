#include<bits/stdc++.h>
using namespace std;
long long a[2002],b[2002];
int main(){

       long long n,x,y;
       cin>>n;
       unordered_map<long long,int> un1;

       for(int i=0;i<n;i++){
              cin>>x;a[i]=x;
              un1[x]++;
       }

       for(int i=0;i<n;i++){
              cin>>y;b[i]=y;
              un1[y]++;
       }

       long long cnt=0;
       for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                     long long k=a[i]^b[j];
                     if(un1[k]!=0){
                            cnt++;
                     }
              }
       }

       if(cnt%2 == 0){
              cout<<"Karen"<<endl;
       } else {
              cout<<"Koyomi"<<endl;
       }

       return 0;
}
