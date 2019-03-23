#include<bits/stdc++.h>
using namespace std;

int todigit(char ch)
{
    return (ch - '0');
}

int sumofsubstrings(string num)
{
    int n = num.length();

    int sumofdigit[n];
    sumofdigit[0] = todigit(num[0]);

    int res = sumofdigit[0];
    for(int i=1; i<n; i++)
    {
        int numi= todigit(num[i]);

        sumofdigit[i] = (i+1)*numi + 10*sumofdigit[i-1];

        res+=sumofdigit[i];
    }
    return res;
}

int main()
{
    string num = "1234";
    cout<<sumofsubstrings(num);
    return 0;
}
