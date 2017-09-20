#include<bits/stdc++.h>
using namespace std;
int n;
long long int m;

map<long long int,int> _m_;
vector<int> vc;
long long int temp;

int main()
{
    scanf("%d%lld", &n,&m);

    for (int i=0; i<n ;i++)
    {
        scanf("%lld", &temp);
        _m_[temp]++;
    }

    int x=1;

    while(m>=x)
    {
        if(_m_[x] == 0)
            {vc.push_back(x);m-=x;}
        x++;
    }

    cout<< vc.size()<<endl;

    for (auto it=vc.begin(); it!=vc.end(); it++)
    {
        printf("%d ", *it);
    }
return 0;
}
