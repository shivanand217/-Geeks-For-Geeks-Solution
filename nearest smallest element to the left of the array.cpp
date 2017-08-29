#include<bits/stdc++.h>
using namespace std;

#define maxn 1005

int a[maxn];
int ans[maxn] = {-1};

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
		cin>>a[i];

    stack<int> st;

    st.push(a[0]);
    int i=1;

    while(i < n)
	{
        int val = a[i];

        while(!st.empty())
		{
            int k = st.top();

            if(k >= val)
				st.pop();
			else{
				ans[i] = k;
				break;
			}

			if(st.empty())
			{
				ans[i] = -1;
			}
		}

		st.push(a[i++]);
	}

    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}
