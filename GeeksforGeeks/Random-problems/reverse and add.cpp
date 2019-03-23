#include<bits/stdc++.h>
#define lli long long int
#define ull unsigned long long int
using namespace std;
#define maxx 4294967295

/** The reverse and add function starts with a number,
reverses its digits, and adds the reverse to the original. If the sum is not a palindrome, repeat this procedure until it does.

Write a program that takes number and gives the resulting palindrome (if one exists).
If it took more than 1,000 iterations (additions) or yield a palindrome that is greater than 4,294,967,295,
assume that no palindrome exist for the given number.
**/

ull reverse_(ull x)
{
    ull rev = 0;
    ull ori = x;

    while(ori)
    {
        rev = rev*10 + ori %10;
        ori/=10;
    }
    return rev;
}

bool check_palindrome(ull x)
{
    string s="";

    while(x)
    {
        s+= x%10 + '0';
        x/=10;
    }

    int i=0, j=s.length()-1;

    while(i < j)
    {
        if(s[i] != s[j])
            return false;
        i++;j--;
    }

    return true;
}

void solve(ull n)
{
for(int i=1; i<=1000; i++)
{
    ull k = reverse_(n);
    n+=k;

    if(check_palindrome(n))
    {
        cout<<n<<endl;
        cout<<"palindrome"<<endl;
        return;
    }
    if(n > maxx)
    {
        cout<<"no palindrome exist"<<endl;
        return;
    }
}

}


int main()
{
 ull n;
 cin>>n;

solve(n);

return 0;
}
