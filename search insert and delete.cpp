#include<bits/stdc++.h>
using namespace std;

// array is sorted
int a[105];
int n;

int b_s(int x)
{
    int mid;
    int lo = 0;
    int hi = n-1;

    while(lo <= hi)
	{
		mid = lo + (hi - lo)/2;

		if(a[mid] == x)
			return mid;
		else if(a[mid] > x)
		{
            hi = mid-1;
		}
		else
		{
            lo = mid+1;
		}
	}

	return -1;
}

void inse(int x)
{
	int lo = 0;
	int hi = n-1;
	int mid;
	int pos;

    while(lo <= hi)
	{
        mid = lo + (hi - lo)/2;

        if(a[mid] >= x)
		{
			pos = mid;
			hi = mid-1;
		}
		else
		{
			pos = mid+1;
            lo = mid+1;
		}
	}

    int p = n;
    while(p > pos)
	{
		a[p] = a[p-1];
        p--;
	}

	a[pos] = x;
	n++;
    return;
}

void del(int x)
{
	int lo = 0;
	int hi = n-1;
	int mid;
	int pos;

	while(lo <= hi)
	{
		mid = lo + (hi - lo)/2;

        if(a[mid] == x)
        {
        	pos = mid;
        	break;
        }

        if(a[mid] > x)
		{
			hi = mid-1;
		}
		else
		{
			lo = mid+1;
		}

        if(lo == hi-1)
		{
            if(a[lo] == x)
				{pos = lo;break;}
			if(a[hi] == x)
				{pos = hi;break;}
			pos = -1;
            break;
		}
	}

	if(pos == -1)
	{
        return;
	}

    while(pos < n)
	{
        a[pos] = a[pos+1];
        pos++;
	}
	n--;
}

void display_array()
{
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}cout<<endl;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
	{
        cin>>a[i];
	}

	int type, query, tmp;
    cin>>query;

while(query--)
{
	cin>>type;

    if(type == 1)// search
	{
		cin>>tmp;
        int ans = b_s(tmp); // O(log(n))
        if(ans == -1)
		{
			cout<<"not found"<<endl;
		}
		else
		{
            cout<<"at position: "<<ans<<endl;
		}
	}
	else if(type == 2)
	{
		// insert
        cin>>tmp;
		inse(tmp); // O(n) in worst case in which we have to shift all the elements
		display_array();
	}
	else
	{
		// delete
        cin>>tmp;
        del(tmp); //O(n) in worst case in which we have to move all the elements
        display_array();
	}
}

	return 0;
}
