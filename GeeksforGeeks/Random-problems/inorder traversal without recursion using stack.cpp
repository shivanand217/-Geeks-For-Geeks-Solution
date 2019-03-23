#include<bits/stdc++.h>
using namespace std;

struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *new_node(int data)
{
    struct tree_node *tmp = (struct tree_node *)malloc(sizeof(struct tree_node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

stack<struct tree_node *> s1;

void inorder(struct tree_node *root)
{
    struct tree_node *curr = root;
    bool done = false;

	while(!done)
	{
		if(curr != NULL)
		{
			s1.push(curr);
			curr = curr->left;
		}
		else
		{
			if(!s1.empty())
			{
				curr = s1.top();
                s1.pop();
				cout<<curr->data<<" ";

                curr = curr->right;
			}
			else
				done = true;
		}
	}
}

void inorder_recursive(struct tree_node *root)
{
    if(root == NULL)
		return;

    inorder_recursive(root->left);
    cout<<root->data<<" ";
    inorder_recursive(root->right);
}

int main()
{
	struct tree_node *root = NULL;

    root = new_node(5);
    root->left = new_node(4);
    root->right = new_node(8);
    root->left->left = new_node(11);
    root->left->left->right = new_node(2);
    root->left->left->left = new_node(7);

    inorder(root);
    cout<<endl;

	return 0;
}
