#include<bits/stdc++.h>
#define max(A,B) ((A>B)?A:B)
using namespace std;

int main()
{
	string s;
	cin>>s;
	int m = 0, f = 0;

	for(int i=0; i<s.length(); i++){
		if(s[i] == 'M')
			m++;
		else if(m)
			f = max(m, f+1);
	}

	printf("%d\n", f);

    return 0;
}
