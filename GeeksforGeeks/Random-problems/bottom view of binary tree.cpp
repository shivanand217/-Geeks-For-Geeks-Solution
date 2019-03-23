#include<bits/stdc++.h>
using namespace std;

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

void solve(struct node *root)
{
    queue<pair<struct node *, int> > qu;
    qu.push(make_pair(root, 0));

    vector<int> ans;
    map<int,int> un;

    pair<struct node *, int> pa;

    while(!qu.empty())
	{
        pa = qu.front();
        qu.pop();

        un[pa.second] = pa.first->data;

        if(pa.first->left != NULL)
		{
			qu.push(make_pair(pa.first->left, pa.second - 1));
		}

		if(pa.first->right != NULL)
		{
            qu.push(make_pair(pa.first->right, pa.second + 1));
		}
	}

    for(auto it = un.begin(); it != un.end(); ++it)
	{
        if(it->second != 0)
        ans.push_back(it->second);
	}

    for(int i=0; i<ans.size(); i++)
	{
       cout<<ans[i]<<" ";
	}cout<<endl;
}

int main()
{
	struct node *root = NULL;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->right = newnode(4);
    root->left->right->right = newnode(5);
    root->left->right->right->right = newnode(6);

    solve(root);

    struct node *root1 = NULL;
	root1 = newnode(2);
	root1->left = newnode(1);
	root1->right = newnode(7);
    root1->left->left = newnode(3);
    root1->left->right = newnode(4);
    root1->left->right->right = newnode(5);
    root1->left->right->right->right = newnode(6);
    root1->left->right->left = newnode(5);
    root1->left->right->left->left = newnode(9);
    root1->left->right->left->left->left = newnode(11);

	solve(root1);

	return 0;
}
