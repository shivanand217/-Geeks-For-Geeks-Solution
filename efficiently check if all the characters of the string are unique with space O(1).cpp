// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n) // n is the length of the string
// SPACE COMPLEXITY : O(1)

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

bool check_unique_characters(string str){
int checker = 0;

   for(int i=0; i<str.length(); i++)
   {
       int x = str[i]-'a';

       if((checker & (1<<x) ) > 0)
        return false;

       // update the checker
       checker=checker|(1<<x);
   }
   return true;
}

int main()
{
string s;
cin>>s;

if(check_unique_characters(s))
{
    cout<<"all character are unique"<<endl;
}
else
{
    cout<<"all the characters are not unique"<<endl;
}
return 0;
}
