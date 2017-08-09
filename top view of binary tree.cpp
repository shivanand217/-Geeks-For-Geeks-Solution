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
    if(root == NULL)
		return;

	unordered_map<int, int> un;
	queue<pair<struct node *, int> > qu;

	vector<int> ans;
	qu.push(make_pair(root, 0));

	pair<struct node *, int> p;

	while(!qu.empty())
	{
		p = qu.front();
		qu.pop();

        if(un.find(p.second) == un.end())
		{
			un[p.second]++;
			ans.push_back(p.first->data);
		}

		if(p.first->left != NULL)
		{
			qu.push(make_pair(p.first->left, p.second - 1));
		}

		if(p.first->right != NULL)
		{
			qu.push(make_pair(p.first->right, p.second + 1));
		}
	}

	int val;

	for(int i=0; i<ans.size(); i++)
	{
        cout<<ans[i]<<" ";
	}
	cout<<endl;
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
