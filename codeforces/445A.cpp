#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d", &x)
char k[102][102];
int main()
{
    int n, m;
    si(n); si(m);
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
            {
                cin>>k[i][j];
                if(((i+j)&1)&&k[i][j]=='.')
					k[i][j]='W';
                if(!((i+j)&1)&&k[i][j]=='.')
                    k[i][j]='B';
            }
    }
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
            cout<<k[i][j];
			}cout<<endl;
		}
    return 0;
}
