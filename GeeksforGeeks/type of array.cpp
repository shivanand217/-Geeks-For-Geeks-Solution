// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** Given an array, it can be of 4 types
1. Ascending
2. Descending
3. Ascending Rotated
3. Descending Rotated
Find out which kind of array it is and return the maximum of that array.
**/
#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define LL long long
#define mod 1000000007
using namespace std;

const int maxn =105;
int ar[maxn];

int n;

int main()
{
    read(n)

    for(int i=0; i<n; i++)
    {
        read(ar[i])
    }

    bool as=false;
    bool des=false;

    string fir="";//string sec="";

    if(ar[0] > ar[1])
           {as = true;fir+="as";}
    else
        {des = true;fir+="des";}

    for(int i=1; i<n-1; i++)
    {
        if(ar[i] > ar[i+1])
        {
            if(des == false)
            {des = true;break;}
        }
        else
        {
            if(as == false)
            {
                as = true;break;
            }
        }
    }

    if(as == true && des == true)
    {
        if(fir == "as")
        {
            cout<<"Type 3"<<endl;
        }
        else
        {
            cout<<"Type 4"<<endl;
        }
    }
    if(as == true && des==false)
    {
        cout<<"Type 1"<<endl;
    }
    if(as == false && des == true)
    {
        cout<<"Type 2"<<endl;
    }

    return 0;
}
