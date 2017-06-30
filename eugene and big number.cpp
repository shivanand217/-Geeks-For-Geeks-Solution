#include<bits/stdc++.h>
using namespace std;

//recuurence problem
// recurrence is
// 20162016 = 10^4*2016 + 2016
// 201620162016 = 20162016 * 10^4 + 2016

long long int m;

vector<vector<long long int> > matmul(vector<vector<long long int> > &A, vector<vector<long long int> > &B)
{
    int n = A.size(),i,j,k;

    vector<vector<long long int> > C(n, vector<long long int>(n));

    for(int i=0; i<n; i++)
	{
        for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
                C[i][j] = (C[i][j]%m + (A[i][k]%m*B[k][j]%m)%m)%m;
			}
		}
	}

	return C;
}

vector<vector<long long int> > matpow(vector<vector<long long int> > A, long long int x)
{
    int n = A.size(), i;

    vector<vector<long long int> > B(n, vector<long long int>(n));
    for(int i=0; i<n; i++)
		B[i][i]=1;

    while(x > 0)
	{
        if(x % 2)
		{
            B = matmul(B, A);
		}

		x/=2;
		A = matmul(A, A);
	}

	return B;
}

int main()
{
    int i,j,k,base=0;
    long long int A,n;

    int t;
    scanf("%d", &t);

    while(t--)
	{
        scanf("%lld %lld %lld", &A, &n, &m);
        int x=1;

        long long int tmp = A;

        while(tmp)
		{
            x*=10;
            tmp/=10;
		}

		vector<vector<long long int> > a(2, vector<long long int>(2));

        a[0][0] = x%m;
        a[0][1] = 1;
        a[1][0] = 0;
        a[1][1] = 1;

        a = matpow(a, n-1);

        printf("%lld\n", ((((a[0][0] + a[0][1])%m)*(A%m)))%m);
	}
	return 0;
}
