#include<bits/stdc++.h>
using namespace std;
int a[1002], b[1002], c[1002];
int main()
{
    int t;
    cin>>t;
    int n1,n2,n3;

	while(t--)
	{
		vector<int> com;
		unordered_map<int, int> ma;

        cin>>n1>>n2>>n3;

        for(int i=0; i<n1; i++)
		{
            cin>>a[i];
		}

        for(int i=0; i<n2; i++)
		{
            cin>>b[i];
		}

        for(int i=0; i<n3; i++)
		{
			cin>>c[i];
		}

        int i=0,j=0,k=0;

        while(i < n1 && j < n2 && k < n3)
		{
            if(a[i] == b[j] && b[j] == c[k])
			{
                if(ma[a[i]] == 0){com.push_back(a[i]);ma[a[i]]++;};
			}

            if(a[i] == min(a[i], min(b[j], c[k])))
			{
				i++;
			}
			else if(b[j] == min(a[i], min(b[j], c[k])))
			{
				j++;
			}
			else if(c[k] == min(a[i], min(b[j], c[k])))
			{
                k++;
			}

		}
        //cout<<com.size()<<endl;

		if(com.size() == 0)
		{
			cout<<"-1"<<endl;
		}
		else{
        for(int i=0; i<com.size(); i++)
		{
            cout<<com[i]<<" ";
		}cout<<endl;
		}

		//com.clear();
	}

	return 0;
}
