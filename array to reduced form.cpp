#include<bits/stdc++.h>
using namespace std;

/** In case if someone don't want to use library function

void MERGE_(vector<pair<int, int> > v, int lo, int mid, int hi)
{
    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    for(int i=0; i<n1; i++)
        Left[i] = make_pair(v[lo + i].first, v[lo+i].second);

    for(int j=0; j<n2; j++)
        Right[j] = make_pair(v[mid + 1 +j].first, v[mid + 1 + j].second);

    int i=0, j=0, k = lo;

    while(i < n1 && j < n2)
	{
        if(Left[i].first < Right[j].first)
		{
			v[k] = make_pair(Left[i].first, Left[i].second);
			i++;
		}
		else
		{
			v[k] = make_pair(Right[j].first, Right[j].second);
			j++;
		}
		k++;
	}

    while(i < n1)
	{
        v[k] = make_pair(Left[i].first, Left[i].second);
        i++; k++;
	}

	while(j < n2)
	{
        v[k] = make_pair(Right[j].first, Right[j].second);
        j++; k++;
	}
}

void MS(vector<pair<int,int> > v, int lo, int hi)
{
    if(lo < hi)
	{
		int mid = lo + (hi - lo)/2;

        MS(v, lo, mid);
        MS(v, mid+1, hi);

        MERGE_(v, lo, mid, hi);
	}
}

**/

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int> > v; int tmp;

    for(int i=0; i<n; i++)
	{
        cin>>tmp;
        v.push_back(make_pair(tmp, i));
	}

	sort(v.begin(), v.end());

    for(int i=0; i<n; i++)
	{
        cout<<v[i].second<<" ";
	}
	cout<<endl;

	return 0;
}
