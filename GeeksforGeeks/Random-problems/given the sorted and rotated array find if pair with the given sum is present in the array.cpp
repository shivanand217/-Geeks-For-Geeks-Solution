// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(log(n) + n)
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
using namespace std;

int ar[102];
int n;

vector<pair<int,int> > answer;

/** i am just using the concept of finding the pivot and then using the man in the middle algorithm in both sides of pivot **/

template<typename T>
void read_(T &x)
{
 char r;
 int start=0,neg=0;
 x=0;

 while(1)
{
 r=getchar();
 if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
    {continue;}
 if((r-'0'<0 || r-'0'>9) && r!='-' && start)
    {break;}

 if(start)
    x*=10;

  start=1;

 if(r=='-')
    neg=1;
 else x += r-'0';
 }

 if(neg)
    x*=-1;
}

int binary_search_(int lo,int hi,int key)
{
    if(hi < lo) return -1;
    int mid = lo + (hi-lo)/2;

    if(ar[mid] == key)
    {
        return mid;
    }
    if(ar[mid] > key)
    {
        return binary_search_(lo, mid-1,key);
    }
    else
    {
        return binary_search_(mid+1,hi,key);
    }
}

int find_pivot(int lo, int hi)
{
    if(hi < lo) return -1; // no pivot

    if(lo == hi)return lo;

    int mid = lo + (hi-lo)/2;

    if(mid < hi && ar[mid+1] < ar[mid])
    {
        return mid;
    }
    if(mid > lo && ar[mid-1] > ar[mid])
    {
        return mid-1;
    }
    if(ar[lo] >= ar[mid])
    {
        return find_pivot(lo, mid-1);
    }
    else
    {
        return find_pivot(mid+1,hi);
    }
}

bool solve(int sum)
{
    int pivot = find_pivot(0,n-1);
    int l=0; int r = pivot;
    int su;

    while(l < r)
    {
        su = ar[l]+ ar[r];
        if(su == sum)
        {
            answer.push_back(make_pair(ar[l],ar[r]));
            l++;
        }
        if(su < sum)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    l = pivot+1;
    r = n-1;

    while(l < r)
    {
        su = ar[l] + ar[r];

        if(su == sum)
        {
            answer.push_back(make_pair(ar[l],ar[r]));
            l++;
        }
        if(su < sum)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    if(answer.size() > 0)
    {
        return true;
    }

    return false;
}

int main()
{
    read_(n);
    for(int i=0; i<n; i++)
    {
        read_(ar[i]);
    }

    int sum;
    read_(sum);

    if(solve(sum))
    {
        cout<<"present"<<endl;
        for(int i=0; i<answer.size(); i++)
        {
            cout<<answer[i].first<<" "<<answer[i].second<<endl;
        }
    }
    else
    {
        cout<<"not present"<<endl;
    }

    return 0;
}
