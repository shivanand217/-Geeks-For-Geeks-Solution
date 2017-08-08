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

void solve(struct node *root, int& max_height, int depth)
{
    if(root == NULL)
		return;

    max_height = max(max_height, depth);

    solve(root->left, max_height, depth+1);
    solve(root->right, max_height, depth+1);
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

    int max_height = 0;
    solve(root, max_height, 1);

	cout<<max_height<<endl;

	return 0;
}
