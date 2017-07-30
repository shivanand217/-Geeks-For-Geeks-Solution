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

void solve(struct tree_node *root, int sum, vector<int> &curr, vector<vector<int> > &ans)
{
    if(root == NULL)
        return;

	sum = sum - root->val;
	curr.push_back(root->val);

    if(root->left == NULL && root->right == NULL)
	{
        if(sum == 0)
		{
            ans.push_back(curr);
		}
		curr.pop_back();
		return;
	}

	solve(root->left, sum, curr, ans);
    solve(root->right, sum, curr, ans);
	curr.pop_back();

    return;
}

int main()
{
	struct tree_node *root = NULL;

    root = new_node(5);
    root->left = new_node(4);
    root->right = new_node(8);
    root->left->left = new_node(11);
    root->left->left->right = new_node(2);
    root->left->left->left = new_node(7);
    root->right->left = new_node(13);
    root->right->right = new_node(4);
    root->right->right->right= new_node(1);
    root->right->right->left = new_node(5);

    int sum=22;
    bool flag = false;

    vector<vector<int> > ans;
    vector<int> curr;

    solve(root, sum, curr, ans);

    for(int i=0; i<ans.size(); i++)
	{
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }cout<<endl;
	}

	return 0;
}
