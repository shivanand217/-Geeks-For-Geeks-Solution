#include<bits/stdc++.h>
using namespace std;

// used recursion
void print(int n, int m, bool k)
{
    cout<<m<<" ";

    if(k == true && n == m)
		return;

    if(!k)
	{
        if(m - 5 > 0)
			print(n , m-5, k);
		else
			print(n, m-5, !k);
	}
	else
		print(n, m+5, k);
}

int main()
{
    int t;
    cin>>t;

    while(t--){

    int n;
    cin>>n;

    print(n, n, false);
    cout<<endl;
    }

    return 0;
}
