#include<bits/stdc++.h>
using namespace std;
char tar[4]={'A','C','T','G'};
int main()
{
	int N;
	string S;
	int ans=0xffffff;
	cin>>N>>S;
	for(int i=0;i<N-3;i++){
		int tmp=0;
		for(int j=0;j<4;j++){
			tmp+=min(abs(S[j+i]-tar[j]),26-abs(S[j+i]-tar[j]));
		}
		ans=min(tmp,ans);
	}
	cout<<ans<<endl;
	return 0;
}