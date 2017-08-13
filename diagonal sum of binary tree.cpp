#include<bits/stdc++.h>
using namespace std;

// O(n)

struct node
{
    int data;
    struct node *left ,*right;
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

void solve(struct node *root , int diagonal, vector<pair<struct node *, int> >& qu)
{
    if(root == NULL)
		return;

    qu.push_back(make_pair(root, diagonal));

    if(root->right != NULL)
	{
		solve(root->right, diagonal, qu);
	}

	if(root->left != NULL)
	{
		solve(root->left, diagonal + 1, qu);
	}

	return;
}

bool comp(pair<struct node *, int> x , pair<struct node *, int>  y)
{
    return x.second < y.second;
}

int main()
{
	struct node *root = NULL;

	root = newnode(1);
	root->left = newnode(2);
	root->left->right = newnode(6);
	root->left->right->left = newnode(11);
	root->left->left = newnode(9);
	root->left->left->right = newnode(10);
	root->right = newnode(3);
	root->right->left = newnode(4);
	root->right->left->right = newnode(7);
	root->right->left->left = newnode(12);
	root->right->right = newnode(5);
	root->right->right->right = newnode(9);
	root->right->right->right->left = newnode(12);
	root->right->right->right->left->right = newnode(2);
	root->right->right->right->left->right->right = newnode(4);
	root->right->right->right->left->right->right->right = newnode(6);

    vector<pair<struct node *, int> > qu;

    solve(root, 0, qu);

    pair<struct node *, int> p;
    sort(qu.begin(), qu.end(), comp);

    int sum = 0;
    int prev;

    for(int i=0; i<qu.size(); i++)
	{
		if(i==0)
			sum += qu[i].first->data;
		else
		{
			if(qu[i].second == prev)
			{
				sum += qu[i].first->data;
			}
			else
			{
                cout<<sum<<" ";
                sum = 0;
                sum += qu[i].first->data;
			}
		}

		prev = qu[i].second;
	}

	cout<<sum<<" ";
	cout<<endl;

	return 0;
}
