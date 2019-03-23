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

void solve(struct node *root, int lo, int hi)
{
	deque<pair<struct node *, int> > de;
	de.push_back(make_pair(root, 1));

	vector<pair<struct node *, int> > ans;
	pair<struct node *, int> pa;

	while(!de.empty())
	{
        pa = de.front();
        de.pop_front();

        if(pa.second >= lo && pa.second <= hi)
		{
			ans.push_back(pa);
		}

		if(pa.first->left != NULL)
		{
			de.push_back(make_pair(pa.first->left, pa.second+1));
		}

		if(pa.first->right != NULL)
		{
			de.push_back(make_pair(pa.first->right, pa.second+1));
		}
	}

	vector<int> level;
	pair<struct node *, int> pa1;

    int prev = 0;

    for(int i=0; i< ans.size(); i++)
	{
		if(i==0)
		{
			cout<<ans[i].first->data<<" ";
		}
		else
		{
			if(ans[i].second == prev)
			{
				cout<<ans[i].first->data<<" ";
			}
			else
			{
                cout<<endl;
                cout<<ans[i].first->data<<" ";
			}
		}
		prev = ans[i].second;
	}

}

int main()
{
	struct node *root = NULL;
    root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->right = newnode(14);
    root->left->right->left = newnode(10);

    int lo = 2, hi = 4;

    solve(root, lo, hi);

    return 0;
}
