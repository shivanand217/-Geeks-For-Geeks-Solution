#include<iostream>
int n,m,i;
int main(){
scanf("%d:%d",&n,&m);
for(;n!=m%10*10+m/10;i++)++m%=60,m?0:++n%=24;
std::cout<<i;
}
