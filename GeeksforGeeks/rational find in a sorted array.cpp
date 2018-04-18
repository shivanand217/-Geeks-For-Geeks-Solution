#include<bits/stdc++.h>
using namespace std;

bool solve(vector<pair<int,int> > Rational, int x, int y)
{
    int high = Rational.size()-1, low = 0, mid;

    while(low <= high)
	{
        mid = low + (high - low)/2;

        if(Rational[mid].first*y == Rational[mid].second*x)
		{
            return true;
		}
		else if(Rational[mid].first*y < Rational[mid].second*x)
		{
            low = mid+1;
		}
		else{
			high = mid-1;
		}
	}

	return false;
}

int main()
{
    int n;
    cin>>n;

    int x , y; // numerator and denom
	vector<pair<int,int> > Rational;

    for(int i=0; i<n; i++)
	{
        cin>>x>>y;
        Rational.push_back(make_pair(x, y));
	}

    cin>>x>>y; // find

    if(solve(Rational, x, y))
		cout<<"yes"<<endl;
	else
        cout<<"no"<<endl;

    return 0;
}
