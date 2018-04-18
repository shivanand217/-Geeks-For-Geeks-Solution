#include<bits/stdc++.h>
using namespace std;

// O(n*m)
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

bool is_same_(struct node *root1, struct node *root2)
{
    if(root1 == NULL && root2 == NULL)
		return true;

	if( (root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
		return false;

    return (root1->data == root2->data && is_same_(root1->left, root1->left) && is_same_(root2->right, root2->right));
}

bool is_subtree(struct node *root1, struct node *root2)
{
	if(root1 == NULL)
		return true;

	if(root2 == NULL)
		return false;

    if(is_same_(root1, root2))
		return true;

	return (is_same_(root1->left, root2->left) || is_same_(root1->right, root2->right));
}

int main()
{
	struct node *root = NULL;
    root = newnode(5);
    root->left = newnode(9);
    root->left->left = newnode(10);

    struct node *root2 = NULL;
    root2 = newnode(4);
    root2->left = newnode(5);
    root2->right = newnode(6);
    root2->left->left = newnode(7);
    root2->left->right = newnode(8);
    root2->right->left = newnode(10);
    root2->right->right = newnode(9);
    root2->right->left->left = newnode(12);
    root2->left->right->left = newnode(11);
    root2->left->right->left->left = newnode(5);
    root2->left->right->left->left->left = newnode(9);
    root2->left->right->left->left->left->left = newnode(10);

	// checking if root is contained in root2 as a subtree
    if(is_subtree(root, root2))
	{
        cout<<"tree of root1 is as a subtree in tree of root2"<<endl;
	}
	else
	{
        cout<<"tree of root1 is not as a subtree in tree of root2"<<endl;
	}

	return 0;
}
