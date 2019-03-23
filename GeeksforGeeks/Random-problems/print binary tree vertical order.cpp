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

void vertical_order(struct node *root, int dir, map<int, vector<int> >& ormap)
{
	if(root == NULL)
		return;

    ormap[dir].push_back(root->data);

    if(root->left != NULL)
		vertical_order(root->left, dir-1, ormap);

	if(root->right != NULL)
		vertical_order(root->right, dir+1, ormap);

    return;
}

int main()
{
	struct node *root = newnode(1);

    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
    root->right->right->right = newnode(9);

    map<int, vector<int> > ormap;

    vertical_order(root, 0, ormap);

    for(auto it=ormap.begin(); it != ormap.end(); ++it)
	{
        for(int i=0; i<ormap[it->first].size(); i++)
		{
            cout<<ormap[it->first][i]<<" ";
		}cout<<endl;
	}

	return 0;
}
