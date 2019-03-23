#include<bits/stdc++.h>
using namespace std;

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

int find_index(int in[], int st, int en, int val)
{
	for(int i=st; i <= en; i++)
	{
		if(in[i] == val)
			return i;
	}
}

struct node *build_tree(int in[], int pre[], int start, int end_)
{
    static int preIndex = 0;
    if(start > end_)
	{
		return NULL;
	}

    struct node *tnew = newnode(pre[preIndex++]);

    if(start == end_)
		return tnew;

    int inIndex = find_index(in, start, end_, tnew->data);

    tnew->left = build_tree(in, pre, start, inIndex-1);
    tnew->right = build_tree(in, pre, inIndex+1, end_);

    return tnew;
}

int main()
{
    int n; // number of nodes in the tree
    cin>>n;

    int *pre = new int[n];
    int *in = new int[n];

    for(int i=0; i<n; i++)
	{
        cin>>pre[i];
	}
    for(int i=0; i<n; i++)
	{
        cin>>in[i];
	}

    struct node *root = NULL;

	root = build_tree(in, pre, 0, n-1);
    inorder(root);

    cout<<endl;

	return 0;
}
