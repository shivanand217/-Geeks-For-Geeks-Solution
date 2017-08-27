#include<bits/stdc++.h>
using namespace std;
#define maxn 1004
int a[maxn], n;

bool comp(int x, int y) { return (x > y); }

int main()
{
    cin>>n;

	int sum = 0;
	bool two=false;

    for(int i=0; i<n; i++)
	{
        cin>>a[i]; sum += a[i];
        if(a[i]%3 == 2)two=true;
	}
    sort(a, a+n, comp);

    if( (sum%3) == 0)
	{
        for(int i=0;i<n;i++)
			cout<<a[i];
		cout<<endl;
	}
	else
	{
        if(sum%3 == 2)
		{
            if(two == false)
			{
                int cnt=0;
                int i=n-1;

                while(i >=0 && cnt != 2)
				{
					if(a[i]%3 == 1){
						cnt++;
						a[i] = -1;
					} i--;
				}
			}
			else{
                int i=n-1;

                while(i>=0)
				{
					if(a[i]%3 == 2){
						a[i] = -1;break;
					} i--;
				}
			}
		}else if(sum%3==1){
            int i=n-1;

            while(i>=0){
				if(a[i]%3 == 1){
					a[i] = -1;break;
				} i--;
            }
		}

        for(int i=0; i<n; i++)
		{
            if(a[i] != -1)
				cout<<a[i];
		}cout<<endl;
	}

    return 0;
}
