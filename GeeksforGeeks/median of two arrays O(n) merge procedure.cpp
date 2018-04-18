#include<bits/stdc++.h>
using namespace std;

long long a[1002];
long long b[1002];
int n;

// O(n) using merging
double find_median()
{
    int i = 0;
    int j = 0;
    int m1 = -1;
    int m2 = -1;

    int m = 0;

    while(m <= n)
	{
        if(i == n)
		{
			m1=m2;
			m2=b[0]; break;
		}
		else if(j == n)
		{
			m1=m2;
			m2=a[0]; break;
		}

		if(a[i] < b[j])
		{
			m1 = m2;
			m2 = a[i];
			i++;
		}
		else
		{
			m1 = m2;
			m2 = b[j];
			j++;
		}

		m++;
	}

    double ans = ((m1+m2)*1.0)/(2*1.0);
    return ans;
}

int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
	{
        cin>>a[i];
	}
    for(int i=0; i<n; i++)
	{
        cin>>b[i];
	}

    double ans = find_median();
    printf("%.7f\n", ans);

	return 0;
}
