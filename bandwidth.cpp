#include<bits/stdc++.h>
using namespace std;

int main()
{
 int t;
 scanf("%d",&t);

 int n;int a;
 int ones;
 int zeros;

 int min_zero_pos,min_one_pos;

 while(t--)
{
    min_zero_pos=INT_MAX; min_one_pos=INT_MAX;

     ones=0;
     zeros = 0;

     scanf("%d",&n);

     for(int i=0; i<n; i++)
     {
         for(int j=0; j<n; j++)
         {
         scanf("%d",&a);
         if(a==0)
         {
             zeros++;
             if(abs(i-j) > 1){
             if(min_zero_pos > abs(i-j))
             {
                 min_zero_pos = abs(i-j);
             }
             }
         }
         else
         {
             ones++;
             if(abs(i-j) > 1)
             {
                 if(min_one_pos > abs(i-j))
                 {
                     min_one_pos = abs(i-j);
                 }
             }
         }

         }
     }

     int p = n*n;

     if(ones == p)
     {
         cout<<n-1<<endl;
     }
     else if(zeros == p)
     {
         cout<<"0"<<endl;
     }
     else
     {
         if(zeros == n || ones == n)
             cout<<"0"<<endl;
         else
         {
              int lp = min(min_zero_pos,min_one_pos);
              if(lp == 1)
                cout<<n-1<<endl;
              else if(lp!=INT_MAX)
              {
                  cout<<lp-1<<endl;
                  }
                  else
                  {
                      cout<<"0"<<endl;
                  }
         }
     }
}

 return 0;
}
