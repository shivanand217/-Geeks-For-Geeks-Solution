#include <iostream>
using namespace std;

int N,M,A,B;
int x;

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>x;
		if(x%2)
			A++;
	}
	for(int i=0;i<M;i++){
		cin>>x;
		if(x%2)
			B++;
	}
	cout<<min(A,M-B)+min(B,N-A);
}