#include<stdio.h>

void add(int a,int b)
{
     int c;
     c =  a + b;
     add (1,1);
}

int main()
{
    add(1, 1);
    return 0;
}
