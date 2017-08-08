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
}

void solve(struct node *root, int sum, int now, bool& ans)
{
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
	{
        if(now+root->data == sum)
		{
            ans = true;
		}
		return;
	}

    solve(root->left, sum, (now+root->data) , ans);
    solve(root->right, sum, (now+root->data) , ans);

    return;
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

    int sum = 16;
    bool ans = false;

    inorder(root);
    cout<<endl;

    solve(root, sum, 0, ans);

    if(ans)
	{
        cout<<"exist"<<endl;
	}
	else
	{
        cout<<"not exist"<<endl;
	}

	return 0;
}
