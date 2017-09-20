#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

std::string binarySort(std::string s)
{
    long n = s.size();
    if(n % 2){return s;}

    std::string left =  binarySort(s.substr(0, n / 2));
    std::string right = binarySort(s.substr(n/2, n / 2));

   // cout<<left<<" "<<right<<endl;
    return left < right ? (left + right) : (right + left);
}


int main()
{
    string s1, s2;
    getline(std::cin, s1);
    getline(std::cin, s2);

    //binarySort(s1);

    puts(binarySort(s1) == binarySort(s2) ? "YES" : "NO");
    return 0;
}
