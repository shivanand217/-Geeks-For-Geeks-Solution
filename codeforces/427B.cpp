#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , t, c;
    cin>>n>>t>>c;

    long long int ans = 0 , tmp;
    int m = -1 , k, val;

    for(int i=0; i<n; i++)
	{
        cin>>tmp;

        if(tmp <= t)
		{
            if(m == -1)
			{
                m = i;
			}

			k = i;
		}
		else
		{
            if(m != -1){

            val = (( k - m + 1) - c + 1);

            if(val > 0)
			{
				ans += val;
			}

            }
				m = -1;
		}
	}
    if(m != -1){

    val = ((k - m + 1) - c + 1);

    if(val > 0)
	{
        ans += val;
	}

    }

    cout<<ans<<endl;

	return 0;
}
