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

void size_of_tree(struct node *root, int& size_)
{
    if(root == NULL)
		return;

    size_ = size_+1;

    size_of_tree(root->left, size_);
    size_of_tree(root->right, size_);
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
	root->right->right->right = newnode(7);
    root->right->left->right = newnode(8);

    int size_ = 0;
    size_of_tree(root, size_);

    cout<<"size of the given binary tree is "<<size_<<endl;

	return 0;
}
