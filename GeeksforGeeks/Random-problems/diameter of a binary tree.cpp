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

int height(struct node *root)
{
    if(root == NULL)
	{
		return 0;
	}
	return (1 + max(height(root->left), height(root->right)));
}

int diameter(struct node *root)
{
	if(root == NULL)
		return 0;

    int left_height = height(root->left);
    int right_height = height(root->right);

    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return max(left_height + right_height + 1, max(left_diameter, right_diameter));
}

int main()
{
	struct node *root = NULL;

    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->right = newnode(4);
    root->left->right->right = newnode(5);
    root->left->right->right->right = newnode(6);

    int diameter_ = diameter(root);
		cout<<diameter_<<endl;

    struct node *root1 = NULL;

	root1 = newnode(2);
	root1->left = newnode(1);
	root1->right = newnode(7);
    root1->left->left = newnode(3);
    root1->left->right = newnode(4);
    root1->left->right->right = newnode(5);
    root1->left->right->right->right = newnode(6);
    root1->left->right->left = newnode(5);
    root1->left->right->left->left = newnode(9);
    root1->left->right->left->left->left = newnode(11);

	diameter_ = diameter(root1);
    cout<<diameter_<<endl;

	return 0;
}
