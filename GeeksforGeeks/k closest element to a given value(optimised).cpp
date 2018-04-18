// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(logn +k)
// SPACE COMPLEXITY: O(1)

/** works for duplicate elements also
**/

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

const int maxn = 1e5+2;
int arr[maxn];int n;
vector<int> ans;// stores the k closest point
int size_;

int mid;int value;

int now_find_last(int v)
{
    for(int i=v; i<n; i++)
    {
        if(arr[i] == value)
            v=i;
    }
    return v;
}

int find_crossover(int low,int high)
{
    //base case
    if(arr[high] <= value)
    {
        return high;
    }
    if(arr[low] > value)
    {
        return low;
    }

    mid=(low+high)/2;

    if(arr[mid] <= value && arr[mid+1] > value)
        return mid;

    if(arr[mid] < value)
       return find_crossover(mid+1,high);

    return find_crossover(low,mid-1);
}

void solve(int cross)
{
    int i=cross;int j=cross+1;

    if(arr[i] == value)
    {ans.push_back(arr[i]);i--;}
    while(i>=0 && j<n && ans.size()<size_)
    {
        if(abs(arr[i] - value) < abs(arr[j]- value))
        {
            ans.push_back(arr[i]);
            i--;
        }
        else
        {
            ans.push_back(arr[j]);
            j++;
        }
    }

    // if size less than k then put remaining
    if(i>=0)
    {
        while(i>=0 && ans.size() < size_)
        {
            ans.push_back(arr[i]);i--;
        }
    }
    if(j<n)
    {
        while(j<n && ans.size() < size_)
        {
            ans.push_back(arr[j]);j++;
        }
    }
}

void print_answer()
{
   for(int i=0; i<ans.size(); i++)
   {
       cout<<ans[i]<<" ";
   }
}

int main()
{
    read(n) read(value) read(size_)

    rr(n)
    {
        read(arr[i])
    }
    int cross=find_crossover(0,n-1);

    solve(cross);
    print_answer();
    ret
}
