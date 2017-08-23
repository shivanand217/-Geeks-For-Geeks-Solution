#include<bits/stdc++.h>
using namespace std;

int a[105], l[105], r[105];

int main()
{
    int t, n, m, i, j, k, sum, max_no;
    cin>>t;

    vector<int> v;

    while(t--)
	{
		sum = 0;
        max_no=INT_MIN;

		v.clear();
        cin>>n;

        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));

        for(i=0; i<n; i++)
            {cin>>a[i]; if(a[i]==0)v.push_back(i);}

		cin>>m;

        if(a[0] == 1)
            l[0]=1;

		for(i=1; i<n; i++)
		{
            if(a[i-1] == 1)
			{
                if(a[i] == 0)
				{
                    l[i]=l[i-1];
				}
				else
				{
                    l[i]=l[i-1]+1;
				}
			}
			else
			{
                if(a[i] == 0)
				{
                    l[i]=0;
				}
				else
				{
                    l[i]=1;
				}
			}
		}

        if(a[n-1] == 1)
            r[n-1]=1;

        for(i=n-2; i>=0; i--)
		{
            if(a[i+1]==1)
			{
				if(a[i]==1)
				{
					r[i]=r[i+1]+1;
				}
				else
				{
                    r[i]=r[i+1];
				}
			}
			else
			{
                if(a[i]==1)
				{
                    r[i]=1;
				}
				else
				{
                    r[i]=0;
				}
			}
		}

        i=0;

        while(i < (n-m+1))
		{
			sum=0;
			j = i;
			k = i+m;

			while(j < k)
			{
                if(j == k-1)
				{
					sum += l[j]+1;
					sum += r[j];
				}
				else
				{
                    sum += l[j]+1;
				}

				j++;
			}

            if(max_no < sum)
				max_no = sum;
			i++;
		}

        cout<<sum<<endl;
	}
    return 0;
}
