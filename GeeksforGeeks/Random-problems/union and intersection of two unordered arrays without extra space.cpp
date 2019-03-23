// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY :  O(mlogm + nlogn)
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
#define fo_r(i,n) for(int i=0; i<n; i++)
using namespace std;

int a[102];
int b[102];

/** another approach using is binary search
    first sort the smaller array
    then for every element of bigger array binary search on smaller array
    if element is not found then print it so if smaller array have n elements
    and bigger elements have m elements
    then it will lead to a complexity of O(m*logn + n*logn)
**/
int n,m;

bool binary_sear(int a[], int m, int fi)
{
    int l=0;
    int r= m-1;

    int mid;

    while(l < r)
    {
        mid = (r-l)/2 + l;

        if(a[mid] == fi)
        {
            return true;
        }
        else if(a[mid] > fi)
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }

    return false;
}

void solve_method1_union_(bool flag)
{
    if(!flag) // then a[] is smaller
    {
        // sort array a
        // use binary search on a on each entry of b
        sort(a,a+n);
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        for(int i=0; i<m; i++)
        {
            if(!binary_sear(a,n,b[i]))
            {
                cout<<b[i]<<" ";
            }
        }
        cout<<endl;
    }
    else // then b[] is smaller
    {
        sort(b,b+m);
        for(int i=0; i<m; i++)
        {
            cout<<b[i]<<" ";
        }

        for(int i=0; i<n; i++)
        {
            if(!binary_sear(b,m,a[i]))
            {
                cout<<a[i]<<" ";
            }
        }
    }
}

// same complexity as union
void solve_method1_intersection_(bool flag)
{
    if(!flag) // a[] is smaller
    {
        sort(a,a+n);
        for(int i=0; i<m; i++)
        {
            if(binary_sear(a,n,b[i]))
            {
                cout<<b[i]<<" ";
            }
        }
        cout<<endl;
    }
    else
    {
        sort(b,b+m);
        for(int i=0; i<n; i++)
        {
            if(binary_sear(b,m,a[i]))
            {
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
}

/**
void union_(int x,int y)
{
    int i=0;int j=0;
    while(i<x && j<y)
    {
        if(a[i] < b[j])
        {
            cout<<a[i++]<<" ";
        }
        else if(b[j] < a[i])
        {
            cout<<b[j++]<<" ";
        }
        else
        {
            cout<<a[i++]<<" ";
            j++;
        }
    }
    while(i<x)
    {
        cout<<a[i++]<<" ";
    }
    while(j<y)
    {
        cout<<b[j++]<<" ";
    }
}

void intersection(int x,int y)
{
    int i=0;int j=0;
    while(i<x && j<y)
    {
        if(a[i] < b[j])
        {
            i++;
        }
        else if(a[i] > b[j])
        {
            j++;
        }
        else
        {
            cout<<a[i++]<<" ";
            j++;
        }
    }
}
**/

int main()
{
    si(n);
    si(m);

    fo_r(i,n)
    {
        si(a[i]);
    }

    fo_r(i,m)
    {
        si(b[i]);
    }

    bool flag = false; // false for a[] is smaller true for b[] is smaller

    if(n > m)
        flag = !flag;

   // solve_method1_union_(flag);
   // solve_method1_intersection_(flag);


   sort(a,a+n); //O(nlogn);
    sort(b,b+m); //O(nlogn);

    union_(n,m); //O(m+n)
    intersection(n,m); //O(m+n)

    return 0;
}


