#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
long long int k1,k2,k3,k4;

lli min_(lli x,lli y,lli z)
{
    if(x< y && x < z)
        return x;
    if(y < x && y < z)
        return y;
    if(z < x && z < y)
        return z;
}

int main()
{
    cin>>k1>>k2>>k3>>k4;

    //int tot=0;

     // count the minimum of the three 2 5 and 6
    lli minn = min(min(k1,k3),k4);
    lli two_fif_six = minn;

       k1-=minn;
       k3-=minn;
       k4-=minn;

    lli minn2=min(k1,k2);
    lli thir_two = minn2;

    lli sum = 256*two_fif_six + 32*thir_two;

cout<<sum<<endl;

}
