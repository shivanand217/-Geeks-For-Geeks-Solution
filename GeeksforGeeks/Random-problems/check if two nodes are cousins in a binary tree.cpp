#include<bits/stdc++.h>
using namespace std;

/** cousins if at same level having different parents **/
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

void solve(struct node *root, int x, int y, int& level1, int& level2, int depth, int& parent1, int& parent2, struct node *prev)
{
    if(root==NULL)
		return;

    if(root->data == x)
	{
        parent1 = prev->data;
        level1 = depth;
	}

	if(root->data == y)
	{
        parent2 = prev->data;
        level2 = depth;
	}

    solve(root->left, x, y, level1, level2, depth+1, parent1, parent2, root);
    solve(root->right, x, y, level1, level2, depth+1, parent1, parent2, root);
    return;
}

int main()
{
    struct node *root = NULL;
    root = newnode(2);
    root->left = newnode(3);
    root->right = newnode(4);
    root->left->left = newnode(5);
    root->left->right = newnode(6);
    root->right->right = newnode(7);
    root->right->left = newnode(8);

    int val1 = 5;
    int val2 = 7;

    int parent1 = -1;
    int parent2 = -1;

    int level1, level2;
    solve(root, val1, val2, level1, level2, 0, parent1, parent2, root);

    cout<<parent1<<" "<<parent2<<endl;

    if(level1 == level2 && parent1 != parent2)
	{
        cout<<"cousin nodes"<<endl;
	}
	else
	{
        cout<<"not cousins"<<endl;
	}

	return 0;
}
