// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)

/** we first scan from left find the first element for which next is smaller set that as start
then scan from right find the first element for which prev is greater set that as end
then sort from start to end now if arr[0..start-1] contain x < arr[start] then set start as index of x
and vice versa for the other part **/

#include<bits/stdc++.h>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define ll long long
using namespace std;

const int maxn = 1e5+2;

int arr[maxn];
int n;

int start=-1,end_=-1;
bool ans=false;

void solve()
{
    for(int i=0; i<n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            start=i;break;
        }
    }

    for(int i=n-1; i>0; i--)
    {
        if(arr[i] < arr[i-1])
        {
            end_=i;
            break;
        }
    }

    if(start == -1 || end_ == -1) // array is sorted
    {
        cout<<"array is sorted"<<endl;ans=true;
    }
    else
    {
        sort(arr+start,arr+end_);

        for(int i=0; i<start; i++)
        {
            if(arr[i] > arr[start])
            {
                start=i;
                break;
            }
        }

        for(int j=end_+1; j<n; j++)
        {
            if(arr[j] < arr[end_])
            {
                end_=j;
                break;
            }
        }
    }
}

int main()
{
    read(n)

    for(int i=0 ;i<n; i++)
    {
        read(arr[i])
    }

    solve();

    //print the answer
    if(ans == false)
    cout<<"the minimum unsorted array is from "<<start<<" to "<<end_<<endl;
    return 0;
}
