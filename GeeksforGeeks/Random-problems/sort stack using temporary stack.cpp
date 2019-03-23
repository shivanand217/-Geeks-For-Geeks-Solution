#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st1,st2;

    int n;
    cin>>n;

    int tmp;
    for(int i=0; i<n; i++)
	{
        scanf("%d", &tmp);
        st1.push(tmp);
	}

    while(st1.empty() == false)
	{
        int k = st1.top();
        st1.pop();

        if(st2.empty() == true)
		{
			st2.push(k);
		}
		else
		{
			int mk = st2.top();
            if(mk < k)
			{
				st2.push(k);
			}
			else
			{
				mk = st2.top();
                while(mk > k)
				{
                    int p = st2.top();
                    st2.pop();
                    st1.push(p);
                    if(st2.empty())break;
                    mk = st2.top();
				}
				st2.push(k);
			}
		}
	}

    while(st2.empty() == false)
	{
        int l = st2.top();
        cout<<l<<" ";
        st2.pop();
	}cout<<endl;

	return 0;
}
