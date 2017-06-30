#include<bits/stdc++.h>
#define ull unsigned long long int
#define mod 1000000007

using namespace std;
vector<ull> magic;

/**ull fast_pow(ull x,ull n)
{
    ull result=1;

    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}**/

void pre()
{
    ull curr_pow = 5;
    int i=9;

    magic.push_back(curr_pow);

    map<ull,int> ma;

    ma[curr_pow]++;
    int j=2;

    while(i--)
	{
        curr_pow = curr_pow*5;
        magic.push_back(curr_pow);
        ma[curr_pow]++;
	}

        for(int i=10; i>=1; i--)
		{
            for(int j=0; j<i; j++)
			{
                ull val = (magic[i]+magic[j]);
                if(ma[val]==0)
				{
					magic.push_back(val);
					ma[val]++;
				}
			}
		}

        for(int i=0; i<magic.size(); i++)
			cout<<magic[i]<<" ";
		cout<<endl;

	sort(magic.begin(), magic.end());
	ma.clear();
}

int main()
{
    int t, n;
    cin>>t;

	pre();

    while(t--)
	{
        cin>>n;n--;
        cout<<magic[n]<<endl;
	}

	return 0;
}
