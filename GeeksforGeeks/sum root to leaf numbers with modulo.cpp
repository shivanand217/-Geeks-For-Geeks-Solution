#include<bits/stdc++.h>
using namespace std;

#define MOD 1003

struct tree_node
{
    int val;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *new_node(int val)
{
    struct tree_node *tmp = (struct tree_node *)malloc(sizeof(struct tree_node));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void solve(struct tree_node *root, int num, int &sum)
{
	if(root == NULL)
		return;

    num = num*10 + root->val;

    if(root->left == NULL && root->right == NULL)
	{
        sum = (sum%MOD + num%MOD)%MOD;
		return;
	}

    solve(root->left, num, sum);
    solve(root->right, num, sum);

    return;
}

void inorder(struct tree_node *root)
{
    if(root == NULL)
		return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
	struct tree_node *root = NULL;
    root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    /**root->left->left = new_node(1);
    root->left->left->right = new_node(2);
    root->left->left->left = new_node(7);
    root->right->left = new_node(1);
    root->right->right = new_node(4);
    root->right->right->right = new_node(1);
    root->right->right->left = new_node(5);
**/

    int sum = 0;
    solve(root, 0, sum);

    cout<<sum<<endl;

	return 0;
}
