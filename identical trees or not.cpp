#include<bits/stdc++.h>
using namespace std;

// identical in data wise and structure wise both

struct node
{
    int data;
    struct node *left, *right;
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

int solve(struct node *root1, struct node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return 1;

    if(root1 != NULL && root2 != NULL)
	{
        return
        {
            ((root1->data == root2->data) && solve(root1->left, root2->left) && solve(root1->right, root2->right))
        };
	}

    return 0;
}

int main()
{
    struct node *root1 = NULL;
    root1 = newnode(2);
    root1->left = newnode(3);
    root1->right = newnode(4);
    root1->left->left = newnode(5);
    root1->left->right = newnode(6);
    root1->right->right = newnode(7);
    root1->right->left = newnode(8);

    inorder(root1);
    cout<<endl;

    struct node *root2 = NULL;
    root2 = newnode(2);
    root2->left = newnode(100);
    root2->right = newnode(4);
    root2->left->left = newnode(5);
    root2->left->right = newnode(6);
    root2->right->right = newnode(7);
    root2->right->left = newnode(8);

    inorder(root2);

	struct node *root3 = NULL;
    root3 = newnode(2);
    root3->left = newnode(100);
    root3->right = newnode(4);
    root3->left->left = newnode(5);
    root3->left->right = newnode(6);
    root3->right->right = newnode(7);
    root3->right->left = newnode(8);

    cout<<endl;

    int is_identical_1_2 = solve(root1, root2);
    if(is_identical_1_2 == 0)
	{
        cout<<"trees 1 and 2 are not identical"<<endl;
	}
	else
	{
        cout<<"trees 1 and 2 are identical"<<endl;
	}

	int is_identical_2_3 = solve(root2, root3);
    if(is_identical_2_3 == 0)
	{
	    cout<<"trees 2 and 3 are not identical"<<endl;
	}
	else
	{
        cout<<"trees 2 and 3 are identical"<<endl;
	}

    int is_identical_1_3 = solve(root1, root3);
	if(is_identical_1_3 == 0)
	{
	    cout<<"trees 1 and 3 are not identical"<<endl;
	}
	else
	{
        cout<<"trees 1 and 3 are identical"<<endl;
	}

	return 0;
}
