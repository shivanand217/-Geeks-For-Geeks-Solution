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

void diagonal_traversal(struct node *root, map<int, vector<int> >& diagonal, int state)
{
    if(root == NULL)
		return;

    diagonal[state].push_back(root->data);

    if(root->left != NULL)
	{
        diagonal_traversal(root->left, diagonal,  state+1);
	}

    if(root->right != NULL)
	{
		diagonal_traversal(root->right, diagonal,  state);
	}
}

int main()
{
	struct node* root = newnode(8);
    root->left = newnode(3);
    root->right = newnode(10);
    root->left->left = newnode(1);
    root->left->right = newnode(6);
    root->right->right = newnode(14);
    root->right->right->left = newnode(13);
    root->left->right->left = newnode(4);
    root->left->right->right = newnode(7);

	map<int, vector<int> > diagonal;

    diagonal_traversal(root, diagonal, 0);

    for(auto it = diagonal.begin(); it != diagonal.end(); it++)
    {
        for(int i=0; i < diagonal[it->first].size(); i++)
		{
            cout<<diagonal[it->first][i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
