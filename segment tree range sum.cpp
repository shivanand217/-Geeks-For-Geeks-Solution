#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n;
int arr[maxn];

// node is the node of the segment tree
int build_tree(int *st,int start,int last,int node)
{

if(start == last)
{
st[node]=arr[start];return st[node];	
}

int mid=(start+last)/2;

st[node] = build_tree(st,start,mid,2*node+1)+build_tree(st,mid+1,last,2*node+2);
return st[node];

}

int *construct_tree()
{

    // number of the nodes in segment tree is 2*n-1
    // height of segment tree
    int x=(int)(ceil(log2(n)));

    int total_nodes=(2*pow(2,x) -1);

    int *seg_tree = new int[total_nodes];

    //fill the values in the segment trees
    build_tree(seg_tree,0,n-1,0);

    return seg_tree;
}

// l ans r are the query bounds
int sum_in_range(int start,int last,int l,int r,int node)
{
	// if the query range lies completly out of current range
	if(l>last || r<start)
		return 0;

	// if the query range lies completly inside the current range
	if(start<=l && last>=r)
	{
		return st[node];
	}

	// for partial interval
	int mid= start + (last-start)/2;
	int left = sum_in_range(start,mid,l,r,2*node+1);
	int right = sum_in_range(mid+1,last,l,r,2*node+2);

	return left+right;
}

int main()
{
	cin>>n; // number of nodes in the array
	// construct the segment tree

	//read the array
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}

	int *s = construct_tree();

	int query;
	cin>>query;

    // query for the sum in a given range

	while(query)
	{
		cin>>left>>right; // 0 index based

	}

}