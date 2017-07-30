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

void print_inorder(struct tree_node *root)
{
    if(root == NULL)
		return;

    print_inorder(root->left);
    cout<<root->val<<" ";
    print_inorder(root->right);
}

void inorder_2(struct tree_node *root, map<int, vector<int> > &m, int move_)
{
    if(root == NULL)
		return;

    inorder_2(root->left, m, move_-1);
    m[move_].push_back(root->val);
    inorder_2(root->right, m, move_+1);
}

int main()
{
    struct tree_node *root = NULL;
    root = new_node(6);
    root->left = new_node(3);
    root->right = new_node(7);
    root->left->left = new_node(2);
    root->left->right = new_node(5);
    root->right->right = new_node(9);

    print_inorder(root);

	map<int, vector<int> > m;
    cout<<endl;

    vector<vector<int> > ans;
    vector<int> curr;

    inorder_2(root, m, 0);

    for(auto it=m.begin(); it != m.end(); it++)
	{
        curr.clear();
        for(int i=m[it->first].size()-1; i>=0 ; i--)
		{
            curr.push_back(m[it->first][i]);
		}
        ans.push_back(curr);
	}

    for(int i=0; i<ans.size(); i++)
	{
        for(int j=0; j<ans[i].size(); j++)
		{
            cout<<ans[i][j]<<" ";
		}cout<<endl;
	}

	return 0;
}
