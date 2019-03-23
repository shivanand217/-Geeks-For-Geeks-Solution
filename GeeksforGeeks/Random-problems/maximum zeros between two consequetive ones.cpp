// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** we have to find maximum zeros between two consequtive ones and we have to output -1 if it contains less than two one **/

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

bool ans=false;

int solve(int n)
{
  int on_1=0;

  int min_one=0;
  int cnt_zero=0;
  int max_zero=0;

  while( n > 0 )
  {
      if(n&1)
      {
          min_one++;
          on_1=1;

          if(cnt_zero > max_zero)
            max_zero = cnt_zero;

          cnt_zero=0;
          n>>=1;
      }
      else
      {
          if(on_1)
          {
              cnt_zero++;
          }
          n>>=1;
      }
  }

  if(min_one < 2)
  {
      ans=true;
      return -1;
  }
  else
    return max_zero;
}

int main()
{
int n;
read(n)

int maximum_ones = solve(n);

if(ans == false)
    cout<<maximum_ones<<endl;
else
    cout<<-1<<endl;

}

