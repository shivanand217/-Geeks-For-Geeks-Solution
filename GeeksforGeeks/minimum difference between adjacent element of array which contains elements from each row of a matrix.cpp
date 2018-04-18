// AUTHOR :SHIV ANAND
// COMPLEXITY O(N*M*log(M))

#include<bits/stdc++.h>
using namespace std;
#define n 2
#define m 2
// int n,m;

// in binary search we are searching for the smallest element in the next row which is greater equal to current value

int b_search(int low,int high,int value,int arr[])
{
    int mid = (low+high)/2;

    while(low <= high)
    {
        if(arr[mid] < value)
            return b_search(mid+1,high,value,arr);
        return b_search(low,mid-1,value,arr);
    }

    return low;
}


int minn_diff(int arr[n][m])
{
    int ans =INT_MAX;

    int p;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0 ;j<m; j++)
        {
           p = b_search(0,m-1,arr[i][j],arr[i+1]);// for each element of arr we are comparing it with element of next row
           ans = min(ans,abs(arr[i+1][p] - arr[i][j]));

           // check if their exist a element x such that it is largest element in next row which is smaller than arr[i][j]
           // that is the element number p-1 because array is sorted

           if(p-1 >= 0)
           {
               ans = min(ans,abs(arr[i+1][p-1] - arr[i][j]));
           }
        }
    }
    return ans;
}


int main()
{
   // scanf("%d%d",&n,&m);

    int arr[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int ans = minn_diff(arr);

    printf("%d\n",ans);

    return 0;
}
