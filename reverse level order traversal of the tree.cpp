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

void reverse_level_order(struct node *root, vector<pair<struct node *, int> >& vec)
{
    if(root == NULL)
		return;

	deque<pair<struct node *, int> > dq;
		dq.push_back(make_pair(root, 0));

	pair<struct node *, int> p;

    while(!dq.empty())
	{
        p = dq.front();
        dq.pop_front();

        vec.push_back(p);

        if(p.first->right != NULL)
		{
            dq.push_back(make_pair(p.first->right, p.second+1));
		}

        if(p.first->left != NULL)
		{
            dq.push_back(make_pair(p.first->left, p.second+1));
		}
	}

	return;
}

int main()
{
	struct node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);
    root->right->left  = newnode(6);
    root->right->right = newnode(7);

    vector<pair<struct node *, int> > vec;

    reverse_level_order(root, vec);
    int prev = vec[vec.size()-1].second;

    cout<<vec[vec.size()-1].first->data<<" ";

    int i = vec.size()-2;

    while(i >= 0)
	{
		if(vec[i].second != prev)
		{
			cout<<endl;
				cout<<vec[i].first->data<<" ";
		}
		else
		{
            cout<<vec[i].first->data<<" ";
		}

		prev = vec[i].second;
		i--;
	}cout<<endl;


    struct node *root1 = newnode(1);
    root1->left        = newnode(2);
    root1->right       = newnode(3);
    root1->left->left  = newnode(4);
    root1->left->right = newnode(5);

    vec.clear();
    reverse_level_order(root1, vec);

	prev = vec[vec.size()-1].second;
    cout<<vec[vec.size()-1].first->data<<" ";

    i = vec.size()-2;

    while(i >= 0)
	{
		if(vec[i].second != prev)
		{
			cout<<endl;
				cout<<vec[i].first->data<<" ";
		}
		else
		{
            cout<<vec[i].first->data<<" ";
		}

		prev = vec[i].second;
		i--;
	}

	return 0;
}
