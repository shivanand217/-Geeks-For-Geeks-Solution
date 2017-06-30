#include<bits/stdc++.h>
using namespace std;

struct tree
{
    int key;
    struct tree *left,*right;
};

struct tree *create(int key)
{
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    root->key = key;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct tree *insert_(struct tree *root, int key)
{
    if(root == NULL)
		return create(key);

    if(key < root->key)
		root->left = insert_(root->left, key);

	else if(key > root->key)
		root->right = insert_(root->right, key);

	return root;
}

void traverse_inorder(struct tree *root)
{
    if(!root)
		return;

    traverse_inorder(root->left);
    cout<<root->key<<" ";
    traverse_inorder(root->right);
}

void solve(struct tree *root, int k, int &c)
{
	// avoiding unnecessary recursive calls
    if(root == NULL || c >= k)
		return;

    solve(root->right, k, c);
    c++;

    if(c == k)
	{
        cout<<root->key<<endl;
	}

    solve(root->left, k, c);
}

int main()
{
    int t;
    cin>>t;

    int n;
    int key ,k;

    while(t--)
	{
        cin>>n;
        cin>>key;
        struct tree *root = NULL;
        root = create(key);

        if(n == 1)
		{
            cin>>k;
            if(k > 1)
			{
				cout<<"-1"<<endl;
			}
			else
			{
				cout<<root->key<<endl;
			}
		}
		else
		{
            for(int i=0; i<n-1; i++)
			{
                cin>>key;
                root = insert_(root, key);
			}

            cin>>k;
            int c = 0;
            solve(root, k, c);
		}
	}
	return 0;
}
