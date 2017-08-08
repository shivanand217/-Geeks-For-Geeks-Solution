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

struct node *delete_tree(struct node *root, int level)
{
    if(root == NULL)
		return NULL;

	root->left = delete_tree(root->left, level+1);
	root->right = delete_tree(root->right, level+1);

    if(level == 0)
	{
        cout<<"root deleted "<<endl;
        free(root);
        root = NULL;
        return root;
	}

    free(root);

    return NULL;
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

    inorder(root);
	cout<<endl;

    root = delete_tree(root, 0);
    inorder(root);

    if(root == NULL)
	{
		cout<<"null"<<endl;
	}

	return 0;
}
