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

void solve(struct node *root, int& sum)
{
    if(root == NULL)
		return;

    if(root->left == NULL && root->right == NULL)
	{
        sum = sum+root->data;
        return;
	}

    solve(root->left, sum);
    solve(root->right, sum);
}

int main()
{
	struct node *root = NULL;
    root = newnode(2);
    root->left = newnode(3);
    root->right = newnode(4);
    root->left->left = newnode(5);
    root->left->right = newnode(6);
    root->right->right = newnode(7);
    root->right->left = newnode(8);
    root->right->right->right =  newnode(1);

    int sum = 0;
    solve(root, sum);
    cout<<"sum of leaves "<<sum<<endl;

	return 0;
}
