#include<stdio.h>
#include<stdlib.h>

long long int perfect_squares[105];

int k=0;

void f(long long int a, long long int b)
{
    long long int t;

int i;
    for(i =1 ; i<=b; i++)
    {
        t = i*i;

        if(t > 1000000007)
        {
            t %= 1000000007;
        }

        if(t <=b && t>=a )
        {
            perfect_squares[k++] = t;
        }
        if(t > b)
        {
            return;
        }
    }
}

int check_divisors(long long int m)
{
    int ans=0;
    int i;

    for(i=1; i*i<=m; i++)
    {
        if(m % i == 0)
        {
            if((m/i) == i)
            {
                ans++;
            }
            else
            {
                ans+=2;
            }
        }
    }
    return ans;
}

int main()
{
    long long int a,b;
    scanf("%lld%lld", &a, &b);

// p is odd
int p;
scanf("%d", &p);

    f(a,b);

int i;

long long int m;

int num;
for(i=0; i<k; i++)
{

m  = perfect_squares[i];
num = check_divisors(m);

if(num == p)
{
printf("%d ", m);
}

}

return 0;
}
