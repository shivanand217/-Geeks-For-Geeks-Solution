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

void solve(struct tree_node *A, int &sum, int B, int &ans, vector<int> &vec, vector<int> &tree)
{
    if(sum == B)
	{
        ans = 1;
	}

    if(A == NULL)
        return;

    sum = sum + A->val;
    solve(A->left, sum, B, ans, vec, tree);

    vec.push_back(sum);
    tree.push_back(A->val);

    if(sum == B)
    {
        ans = 1;
    }

    solve(A->right, sum, B, ans, vec, tree);
    sum = sum - A->val;
}

int main()
{
	struct tree_node *root = NULL;

    root = new_node(5);
    root->left = new_node(1000);
    root->right = new_node(200);
    root->left->left = new_node(2);
    root->left->right = new_node(5);
    root->right->right = new_node(9);

    int b = 1000;
    int sum = 0;

    vector<int> vec, tree;

    int ans=0;
    solve(root, sum, b, ans, vec, tree);

    for(int i=0; i<tree.size(); i++)
	{
        cout<<tree[i]<<" ";
	}cout<<endl;

    for(int i=0; i<vec.size(); i++)
	{
        cout<<vec[i]<<" ";
	}cout<<endl;

    if(ans == 0)
	{
        cout<<"No"<<endl;
	}
	else
	{
        cout<<"Yes"<<endl;
	}

    return 0;
}
