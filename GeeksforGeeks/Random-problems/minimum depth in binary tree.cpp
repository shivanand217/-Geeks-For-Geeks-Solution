#include<bits/stdc++.h>
using namespace std;

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

void solve(struct tree_node *root, int depth, int max_, int &min_)
{
    if(root == NULL)
	{
        return;
	}

    max_ = max(depth, max_);

    if(root->left == NULL && root->right == NULL)
	{
        min_ = min(min_, max_);
        return;
	}

    solve(root->left, depth+1, max_, min_);
    solve(root->right, depth+1, max_, min_);

    return;
}

int main()
{
	struct tree_node *root = NULL;
    root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(8);
    root->left->left = new_node(11);

    /**root->left->left->right = new_node(2);
    root->left->left->left = new_node(7);
    root->right->left = new_node(13);
    root->right->right = new_node(4);
    root->right->right->right= new_node(1);
    root->right->right->left = new_node(5);
**/

    int max_ = INT_MIN;
    int min_ = INT_MAX;

    solve(root, 1, max_, min_);

    cout<<min_<<endl;

	return 0;
}
