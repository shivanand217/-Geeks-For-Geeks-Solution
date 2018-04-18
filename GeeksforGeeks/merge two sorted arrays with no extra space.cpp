// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*m)
// SPACE COMPLEXITY : O(1)

/**

    awesome problem  merge two sorted arrays with no extra space
    i am using the method of insertion sort for the insertion

    **/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
using namespace std;

int ar1[102];
int ar2[102];

int main()
{
    int n,m;

    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++)
    {
        scanf("%d", &ar1[i]);
    }

    for(int j=0; j<n; j++)
    {
        scanf("%d", &ar2[j]);
    }

    for(int i=n-1; i>=0; i--)
    {
        int j, last=ar1[m-1];

        for(j = m-2; j>=0 && ar1[j] > ar2[i]; j--)
        {
            ar1[j+1] = ar1[j];
        }

        if(j != m-2 || last > ar2[i])
        {
            ar1[j+1] = ar2[i];
            ar2[i] = last;
        }
    }

/**    while(i >= 0)
    {
        k=n-1;

        if(ar1[k] > ar2[i]){

        while(ar1[k] > ar2[i] && k>=0)
        {
            k--;
        }

        k++;

        fi = ar1[n-1];
        ori = ar2[i];
        t1 = ar1[k];
        ar1[k] = ori;

        k++;

            for(int mm = k; mm<n-1; mm++)
            {
                t2 = ar1[k];

                ar1[k] = t1;

                t1 = ar1[k+1];
            }
    }
    else
    {
        i--;
    }

    }
    **/

    for(int i=0; i<m; i++)
    {
        cout<<ar1[i]<<" ";
    }

    for(int i=0; i<n; i++)
    {
        cout<<ar2[i]<<" ";
    }

    cout<<endl;
    return 0;
}
