#include<bits/stdc++.h>
using namespace std;
long long int a[600005];
long long int getSum(long long int BIT[], int index)
{
    index++;
    long long int sum=0;
    while(index > 0)
	{
        sum += BIT[index];
        index = index - (index & (-index));
	}
	return sum;
}
void update(long long int BIT[], int n,int index, long long int val)
{
    index++;
    while(index <= n)
	{
        BIT[index] += val;
        index = index + (index & (-index));
	}
}
long long int *build(int n)
{
    long long int *BIT = new long long int[n+1];
    for(int i=1; i<=n; i++)
		BIT[i]=0;
    for(int i=0; i<n; i++)
		update(BIT, n, i, a[i]);
	return BIT;
}

int main()
{
    int n;
    cin>>n;
    long long int sum=0;
    for(int i=0;i<n;i++)
	{
        cin>>a[i];
        sum += a[i];
	}
    if(sum % 3 != 0)
	{
        cout<<"0"<<endl;return 0;
	}
    long long int *BIT = build(n+1);
    int f=5, s=4;
    long long int curr, curr2;
    int ans = 0;
    for(int i=0;i<n-2;i++)
	{
        curr = getSum(BIT, i);
        for(int j=i+1;j<n-1;j++)
		{
			curr2 = getSum(BIT, j) - curr;
            if(curr2 == curr)
				if(getSum(BIT, n-1) - getSum(BIT, j) == curr)
					ans++;
 		}
	}
    cout<<ans<<endl;
    return 0;
}
