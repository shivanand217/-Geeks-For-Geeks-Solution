#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int pre[1000005];

int main()
{
    int t;
    cin>>t;
	bool ans;

    long int start, L, R, o2, o1;
    long int cnt;
    long int blocks, new_blocks;
    long int n;

    vector<pair<long int,long int> > v;

    while(t--)
	{
        cin>>o1>>o2;

        for(long int i=1; i<=o1*o2; i++)
		{
            cin>>a[i];
		}

        (a[1]==0) ? pre[1] = 0 : pre[1] = 1;

        for(long int i=2; i<=o1*o2; i++)
		{
            pre[i] = (a[i]==0) ? pre[i-1] : (1 + pre[i-1]);
		}

        start = 1;
        ans = false;
        blocks = 0;
        n = o1*o2;

        while(start <= n-o2)
		{
			if(ans)
				break;

            cnt=0;

            if(start == 1)
			{
                L = 1;
				R = o2;

                if(pre[R] > (R-L+1)/2)
					cnt++;

				blocks++;
                //v.push_back({L,R});

                L = (L + o2)%n;
                R = (R + o2)%n;

                while(L <= n-o2+1)
				{
                    //v.push_back({L,R});
                    blocks++;

					if(R < L)
					{
                        if(pre[n] - pre[L-1] + pre[R] > (n - L + 1) + (R-1+1)/2)
							cnt++;
					}
					else
					{
                        if(pre[R] - pre[L-1] > (R - L + 1)/2)
							cnt++;
					}

                    L = (L + o2);
                    R = (R + o2);
				}

				/**for(int i=0; i<v.size(); i++)
				{
                    cout<<v[i].first<<" "<<v[i].second<<endl;
				}**/

                if(cnt > floor(blocks/2))
				{
                    ans = true;
				}
				//v.clear();cout<<endl;
			}
			else
			{
				new_blocks = 0;

                L = start%n;
                R = (start+o2-1)%n;

				if(R < L)
				{
                        if(pre[n] - pre[L-1] + pre[R] > (n - L + R)/2)
							cnt++;
				}
				else
				{
                        if(pre[R] - pre[L-1] > (R - L + 1)/2)
							cnt++;
				}

                new_blocks++;
                //v.push_back({L,R});
                while(new_blocks < blocks)
				{
					L = (L + o2)%n;
					R = (R + o2)%n;
                  //  v.push_back({L,R});

					if(R < L)
					{
                        if(pre[n] - pre[L-1] + pre[R] > (n - L + R)/2)
							cnt++;
					}
					else
					{
                        if(pre[R] - pre[L-1] > (R - L + 1)/2)
							cnt++;
					}

                    new_blocks++;
				}
				/**for(int i=0; i<v.size(); i++)
				{
                    cout<<v[i].first<<" "<<v[i].second<<endl;
				}**/
                if(cnt > floor(blocks)/2)
				{
                    ans = true;
				}
                //v.clear();cout<<endl;
		  }
			start++;
		}
        if(ans)
		{
            cout<<"1"<<endl;
		}
		else
		{
            cout<<"0"<<endl;
		}
	}
return 0;
}
