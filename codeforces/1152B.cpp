#include<bits/stdc++.h>
using namespace std;
int a,j=19,k;
int main(){
	cin>>a;
	cout<<"39\n";
	while(j--){
		k=log2(a)+1;
		a^=(int)(pow(2,k)-1);
		a++;
		cout<<k<<' ';
	}
	cout<<log2(a)+1;
}