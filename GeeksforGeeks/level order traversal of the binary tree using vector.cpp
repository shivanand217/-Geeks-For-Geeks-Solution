#include<bits/stdc++.h>
using namespace std;

// complexity -> O(nlogn)
struct node
{
    char data;
    struct node *left, *right;
};

struct node *newnode(char data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

/** inorder
void print(struct node *root)
{
    if(root == NULL)
		return;

	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
    return;
}**/

bool comp(pair<struct node *, int> x, pair<struct node *, int> y)
{
    return (x.second < y.second);
}

void level_order(struct node *root_l, struct node *root_r, vector<pair<struct node *, int> > &qu, int move_)
{
    if(root_l == NULL && root_r == NULL)
		return;

    if(root_l != NULL)
	{
        qu.push_back(make_pair(root_l, move_));
	}
	if(root_r != NULL)
	{
		qu.push_back(make_pair(root_r, move_));
	}

    if(root_l == NULL)
	{
        level_order(root_r->left, root_r->right, qu, move_+1);
	}
	else if(root_r == NULL)
	{
        level_order(root_l->left, root_l->right, qu, move_+1);
	}
	else
	{
		level_order(root_l->left, root_l->right, qu, move_+1);
		level_order(root_r->left, root_r->right, qu, move_+1);
	}
}

int main()
{
    struct node *root = NULL;

    root = newnode('A');
    root->left = newnode('B');
    root->right = newnode('C');
    root->left->left = newnode('D');
    root->right->right = newnode('G');
    root->right->left = newnode('F');
    root->left->right = newnode('E');
    root->left->left->left = newnode('H');
    root->right->right->right = newnode('I');
    root->left->left->left->right = newnode('J');
    root->right->right->right->left = newnode('K');


    vector<pair<struct node *, int> > qu;
    qu.push_back(make_pair(root, 0));

    level_order(root->left, root->right, qu, 1);
    sort(qu.begin(), qu.end(), comp);

    int prev = 0;
	auto it = qu.begin();

    while(qu.size() != 0)
	{
		it = qu.begin();

        if(it->second == prev)
		{
			cout<<it->first->data<<" ";
		}
		else
		{
            cout<<endl;
            cout<<it->first->data<<" ";
		}

		prev = it->second;
        qu.erase(qu.begin());
	}

	cout<<endl;

	return 0;
}
