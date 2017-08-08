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

struct node *solve(struct node *root, int level, int k)
{
    if(root == NULL)
		return NULL;


	if(root->left == NULL && root->right == NULL)
	{
        if(level < k)
		{
            free(root);
            return NULL;
		}
	}

    root->left = solve(root->left, level+1, k);
    root->right = solve(root->right, level+1, k);

    return root;
}

int main()
{
    struct node *root = NULL;
	root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);
    root->right->right->left = newnode(8);
    root->left->left->left = newnode(7);

    inorder(root);
    root = solve(root, 1, 4);

    cout<<endl;
    inorder(root);

    return 0;
}
