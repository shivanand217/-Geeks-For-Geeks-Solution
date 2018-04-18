// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY: O(n*n)
// SPACE COMPLEXITY: O(1)


/**
A string is called a palindrome if it may be read the same way in either direction. 
For example, “12321” is a palindrome, but “12341” is not. 
A palindrome string can itself compose of one or more palindrome sub-strings. 
Now, your task is to find out the length (denoted by L) of the longest palindrome sub-string, 
maximum-length contiguous substring of a given string that is also a palindrome, 
and print "YES" if it is lucky otherwise print "NO". A palindrome sub-string is called lucky iff it's length is a prime number.
For example : Consider a string s =”122321”. The longest palindrome sub-strings in s is of length 3. 
Hence, you need to output "YES" (quotes only for clarity).

**/

#include<bits/stdc++.h>
using namespace std;
#define boostio std::ios::sync_with_stdio(false);cin.tie(NULL);

bool is_prime[1005];

void seive()
{
    memset(is_prime,true,sizeof(is_prime));

    is_prime[0]=false;is_prime[1]=false;
    for(int i=2; i*i<=1005; i++)
    {
        if(is_prime[i] == true)
        {
        for(int j=i*2; j<=1005; j+=i)
        {
        is_prime[j]=false;
        }
        }
    }
}

bool check_lucky_string(string s)
{
    int low;
    int high;

    int max_length=1;

    for(int i=1; i<s.length(); i++)
    {
        // check for substring as i-1 ans i as center
        low = i-1;high=i;

        while(low >= 0 && high < s.length() && s[low]==s[high])
        {
            if(high-low+1 > max_length)
            {
                max_length = high-low+1;
            }
            low--;
            high++;
        }

        // checking for substring as i as center
        low = i-1;
        high = i+1;

        while(low >= 0 && high < s.length() && s[low]==s[high])
        {
            if(high-low+1 > max_length)
            {
                max_length = high-low+1;
            }
            low--;
            high++;
        }
    }

//cout<<max_length<<endl;

    if(is_prime[max_length] == true)
    {
        return true;
    }
    else
    {
     return false;
    }
}

int main()
{
    boostio;
    int t;
    cin>>t;

    string s;

    while(t--)
    {
     cin>>s;
     if(check_lucky_string(s))
     {
         cout<<"YES"<<endl;
     }
     else
     {
         cout<<"NO"<<endl;
     }
    }

return 0;
}
