#include<bits/stdc++.h>
using namespace std;

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

void level_order(queue<pair<struct node *, int> > qu)
{
    int prev = 0;
    pair<struct node *, int> p;

    while(!qu.empty())
	{
		p = qu.front();
        qu.pop();

        if(prev == p.second)
		{
            cout<<p.first->data<<" ";
		}
		else
		{
            cout<<endl;
            cout<<p.first->data<<" ";
		}

        prev = p.second;

        if(p.first->left != NULL)
		{
			qu.push(make_pair(p.first->left, p.second+1));
		}

		if(p.first->right != NULL)
		{
            qu.push(make_pair(p.first->right, p.second+1));
		}
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

	queue<pair<struct node *, int> > qu;
    qu.push(make_pair(root, 0));

    level_order(qu);

	return 0;
}
