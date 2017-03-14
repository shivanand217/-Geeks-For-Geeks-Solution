#include<bits/stdc++.h>
using namespace std;

int set_count(int p)
{
    int cnt_=0;

    while(p>0)
    {
        if(p&1)
        {
            cnt_++;
        }
        p>>=1;
    }
    return cnt_;
}

// Function to calclate K bit different pairs in array
long long kBitDifferencePairs(int arr[], int n, int k)
{
    // Get the maximum value among all array elemensts
    int MAX = *max_element(arr, arr+n);

    // Set the count array to 0, count[] stores the
    // total frequency of array elements
    long long count[MAX+1];
    memset(count, 0, sizeof(count));

    for (int i=0; i < n; ++i)
        ++count[arr[i]];

    // Initialize result
    long long ans = 0;

    // For 0 bit answer will be total count of same number
    if (k == 0)
    {
        for (int i = 0; i <= MAX; ++i)
            ans += (count[i] * (count[i] - 1)) / 2;

        return ans;
    }

    for (int i = 0; i <= MAX; ++i)
    {
        // if count[i] is 0, skip the next loop as it
        // will not contribute the answer
        if (!count[i])
           continue;

        for (int j = i + 1; j <= MAX; ++j)
        {
            //Update answer if k differ bit found
            if ( set_count(i^j) == k)
                ans += count[i] * count[j];
        }
    }
    return ans;
}

// Driver code
int main()
{
    int k = 2;
    int arr[] = {2, 4, 1, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Total pairs for k = " << k << " are = "
         << kBitDifferencePairs(arr, n, k) << "\n";

    k = 3;
    cout << "Total pairs for k = " << k << " are = "
         << kBitDifferencePairs(arr, n, k) ;
    return 0;
}
