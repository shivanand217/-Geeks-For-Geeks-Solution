#include<bits/stdc++.h>
using namespace std;

// complexity O(n)
struct node
{
    int data;
    struct node *left, *right;
};

struct node *newnode(int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void inorder(struct node *root)
{
	if(root == NULL)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

void solve(int root, int& height, map<int, vector<int> > mapp, int depth)
{
    height = max(height, depth);

    if(mapp[root].size() == 2)
	{
        solve(mapp[root][0], height, mapp, depth+1);
        solve(mapp[root][1], height, mapp, depth+1);
	}
    else if(mapp[root].size() == 1)
	{
        solve(mapp[root][0], height, mapp, depth+1);
	}

	return;
}

int main()
{
	int n;
	cin>>n;

    int *parent = new int[n];
    int root;

    for(int i=0; i<n; i++)
	{
        cin>>parent[i];
        if(parent[i] == -1)
		{
            root = i;
		}
	}

	map<int, vector<int> > mapp;
    for(int i=0; i<n; i++)
	{
        mapp[parent[i]].push_back(i);
	}

	int height  = 0;

    solve(root ,height , mapp, 1);
    cout<<height<<endl;

	return 0;
}
