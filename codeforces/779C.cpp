#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n,k,i,sum=0;
	cin>>n>>k;
	int a[n],b[n];
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) {
		cin>>b[i];
		sum+=b[i];
		b[i]=a[i]-b[i];
	}
	sort(b,b+n);
	for(i=0;k-->0||b[i]<0;i++)
		sum+=b[i];
	cout<<sum;
}
