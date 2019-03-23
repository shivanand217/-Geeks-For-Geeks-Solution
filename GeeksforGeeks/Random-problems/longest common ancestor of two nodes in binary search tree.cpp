#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left ,*right;
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

struct node *lca;

void solve(struct node *root, int n1, int n2)
{
    if(root == NULL)
		return;

    if(root->data > n1 && root->data > n2)
	{
        solve(root->left, n1, n2);
	}
	else if(root->data < n1 && root->data < n2)
	{
		solve(root->right , n1, n2);
	}
	else if(root->data > n1 && root->data < n2 || (root->data == n2) || (root->data == n1))
	{
		lca = root;
		return;
	}

    return;
}

int main()
{
	struct node *root = NULL;
    root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->right = newnode(12);
    root->left->left = newnode(4);
    root->left->right->right = newnode(14);
    root->left->right->left = newnode(10);

    int n1=8, n2=14;

	solve(root, n1, n2);

    cout<<"lca of nodes "<<n1<<" and "<<n2<<" is "<<(lca->data)<<endl;

    return 0;
}
