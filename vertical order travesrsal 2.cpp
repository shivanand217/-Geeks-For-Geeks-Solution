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

void solve(struct tree_node *root, map<int, vector<int> > &m)
{
    if(root == NULL)
		return;

    queue<pair<struct tree_node *, int> > qu;
    qu.push(make_pair(root, 0));

    while(!qu.empty())
	{
        pair<struct tree_node *, int> p;
        p = qu.front();
        qu.pop();

        int vertical_dist = p.second;
        struct tree_node *tmp = p.first;

        m[vertical_dist].push_back(tmp->val);

        if(tmp->left != NULL)
		{
            qu.push(make_pair(tmp->left, vertical_dist - 1));
		}
		if(tmp->right != NULL)
		{
            qu.push(make_pair(tmp->right, vertical_dist + 1));
		}
 	}
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

    map<int, vector<int> > m;
    solve(root, m);

    for(auto it=m.begin(); it != m.end(); it++)
	{
        for(int i=0; i < m[it->first].size(); i++)
		{
            cout<<m[it->first][i]<<" ";
		}
	}

	return 0;
}
