#include<bits/stdc++.h>
using namespace std;
int main()
{
       int n,x,tmp;
       cin>>n>>x;
       unordered_map<int,int>un;
       for(int i=0;i<n;i++)
       {
              cin>>tmp;
              un[tmp]++;
       }
       int op=0;
       for(int i=0;i<=x;i++)
       {
              if(i==x)
              {
                     if(un[x]>0)
                          op++;
              }
              else{
                     if(un[i]==0)
                     op++;
              }
       }
       cout<<op<<endl;
       return 0;
}
