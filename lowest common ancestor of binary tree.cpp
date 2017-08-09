#include<bits/stdc++.h>
using namespace std;

// using O(n) extra space
// storing paths from root to n1 and n2
// element before the first mismatch in the paths will be the LCA of both the two

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

bool solve(struct node *root, vector<int>& path, int n)
{
    if(root == NULL)
		return false;

    if(root->data == n)
		return true;

	path.push_back(root->data);

	if(solve(root->left, path, n) || solve(root->right, path, n))
	{
		return true;
	}

    path.pop_back();
    return false;
}

int LCA(struct node *root, int n1, int n2)
{
	vector<int> path1, path2;

	// any of the two values not in the tree
	if( !solve(root, path1, n1) || !solve(root, path2, n2))
	{
		return -1;
	}

	int lca=-1; // return the value just before the first mismatch

 	for(int i=0; (i < path1.size()) && (i < path2.size()); i++)
	{
		if(path1[i] != path2[i])
		{
            break;
		}
			else
				lca = (path1.size() < path2.size()) ? (path1[i]) : (path2[i]);
	}

	return lca;
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
    root->left->right->left = newnode(10);

    int lca;

    lca = LCA(root, 10, 6);
    cout<<lca<<endl;

	return 0;
}
