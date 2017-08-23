#include<bits/stdc++.h>
using namespace std;

int arr[105];

int findZeroes(int n, int m)
{
    int wL = 0, wR = 0;
	int bestL = 0, bestWindow = 0;
    int zeroCount = 0;

    while (wR < n)
    {
        if (zeroCount <= m)
        {
            if (arr[wR] == 0)
              zeroCount++;
            wR++;
        }

        if (zeroCount > m)
        {
            if (arr[wL] == 0)
              zeroCount--;
            wL++;
        }

        if (wR-wL > bestWindow)
        {
            bestWindow = wR-wL;
            bestL = wL;
        }
    }

    return (bestWindow);
}

int main()
{
    int t, n, m;
    cin>>t;

    while(t--)
	{
        cin>>n;
        for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
        cin>>m;

		int ans = findZeroes(n, m);
		cout<<ans<<endl;
	}

	return 0;
}
