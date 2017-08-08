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

int height(struct node *root)
{
    if(root == NULL)
        return 0;
    return (1 + max(height(root->left), height(root->right)));
}

bool solve(struct node *root, int& max_height, int depth)
{
    if(root == NULL)
		return true;

	max_height = max(max_height, depth);
    int left_height ,right_height;

	bool ans = true;

    left_height = height(root->left);
    right_height = height(root->right);

    if(abs(left_height - right_height) > 1)
        ans = false;

    return (ans && solve(root->left, max_height, depth+1) && solve(root->right, max_height, depth+1));
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
	bool ans = solve(root, max_height, 0);

    if(ans == false)
	{
        cout<<"tree is not height balanced "<<endl;
	}
	else
	{
        cout<<"tree is height balanced "<<endl;
	}

    return 0;
}
