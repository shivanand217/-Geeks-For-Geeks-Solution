// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

// their is a formula to calculate this
// kamentsky formula

// f(x)= log10((n/e)^n*sqrt(2*pi*n))
// solving log f(x) = (n*log10(n/e)) + (log(2*pi*n)/2)

#include<bits/stdc++.h>
#include<cmath>

#define _USE_MATH_DEFINES

using namespace std;
#define MOD 1000000007
#define M_E 2.71828
const double M_PI = 3.14159265358979323846;

long long n;

long long digits_()
{
    if(n<0)
        return 0;

    if(n<=1)
        return 1;

    double sum = n*log10(n/M_E) + (log10(2*M_PI*n))/2.0;

    return floor(sum)+1;
}

int main()
{
    scanf("%lld",&n);
    int p = digits_();

    printf("%d\n",p);
    return 0;
}
