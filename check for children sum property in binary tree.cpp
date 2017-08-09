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

void solve(struct node *root, bool& ans)
{
	if(root == NULL)
		return;

	if(root->left != NULL && root->right != NULL)
	{
        if(root->data != (root->left->data + root->right->data))
		{
			ans = false;
			return;
		}
		solve(root->left, ans);
		solve(root->right, ans);
	}
	else if(root->left == NULL && root->right != NULL)
	{
		if(root->data != root->right->data)
		{
			ans = false;
			return;
		}
		solve(root->right, ans);
	}
	else if(root->left != NULL && root->right == NULL)
	{
        if(root->data != root->left->data)
		{
			ans = false;
            return;
		}
		solve(root->left, ans);
	}
}

int main()
{
	struct node *root = NULL;
    root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->right = newnode(5);
    root->left->left = newnode(3);
    root->right->right = newnode(9);

    bool ans = true;

    solve(root, ans);

    if(ans)
        cout<<"given tree satisfies children sum property"<<endl;
	else
        cout<<"tree doesn't satisfies children sum property"<<endl;


	struct node *root1 = NULL;
    root1 = newnode(10);
    root1->left = newnode(8);
    root1->right = newnode(2);
    root1->left->right = newnode(5);
    root1->left->left = newnode(3);
    root1->right->right = newnode(2);

    ans = true;
	solve(root1, ans);

	if(ans)
        cout<<"given tree satisfies children sum property"<<endl;
	else
        cout<<"tree doesn't satisfies children sum property"<<endl;

	return 0;
}
