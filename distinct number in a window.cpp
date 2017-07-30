#include<bits/stdc++.h>
using namespace std;

vector<int> ans(vector<int> &A, int B)
{
    unordered_map<int,int> un;
    vector<int> ans;

    int i=0;
    int cnt=0;
    int j=0;

    while(i < B)
    {
        if(un[A[i]] == 0)
        {
            cnt++;
            un[A[i]]++;
        }
        else
		{
            un[A[i]]++;
		}
        i++;
    }

    ans.push_back(cnt);
    while(i < A.size())
    {
        un[A[j]]--;

        if(un[A[j]] == 0)
        {
            cnt--;
        }

        if(un[A[i]] == 0)
        {
            cnt++;
            un[A[i]]++;
        }
        else
        {
            un[A[i]]++;
        }

        ans.push_back(cnt);

        i++;
        j++;
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> A;
    int tmp;

    for(int i=0; i<n; i++)
	{
        cin>>tmp;
        A.push_back(tmp);
	}

	int k=3;
    vector<int> a1 = ans(A, k);

    for(int i=0; i<a1.size(); i++)
	{
        cout<<a1[i]<<" ";
	}cout<<endl;

	return 0;
}
