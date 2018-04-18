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

void solve(struct node *root, vector<vector<struct node *> >& ans, vector<struct node *> path)
{
    if(root == NULL)
		return;

	if(root->left == NULL && root->right == NULL)
	{
		path.push_back(root);
        ans.push_back(path);
        return;
	}

    path.push_back(root);

    if(root->left)
		solve(root->left, ans, path);

	if(root->right)
		solve(root->right, ans, path);

	return;
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
    vector<vector<struct node *> > ans;
    vector<struct node *> path;
    solve(root, ans, path);
    for(int i=0; i<ans.size(); i++)
	{
        for(int j=0; j<ans[i].size(); j++)
		{
            cout<<ans[i][j]->data<<" ";
		}cout<<endl;
	}cout<<endl;

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
    ans.clear();
    path.clear();
    solve(root1, ans, path);
	for(int i=0; i<ans.size(); i++)
	{
        for(int j=0; j<ans[i].size(); j++)
		{
            cout<<ans[i][j]->data<<" ";
		}cout<<endl;
	}cout<<endl;

    struct node *root2 = NULL;
    root2 = newnode(1);
    root2->left = newnode(2);
    root2->right = newnode(3);
    root2->left->left = newnode(4);
    root2->left->right = newnode(5);
    ans.clear();
    path.clear();
    solve(root2, ans, path);
	for(int i=0; i<ans.size(); i++)
	{
        for(int j=0; j<ans[i].size(); j++)
		{
            cout<<ans[i][j]->data<<" ";
		}cout<<endl;
	}cout<<endl;

	return 0;
}
