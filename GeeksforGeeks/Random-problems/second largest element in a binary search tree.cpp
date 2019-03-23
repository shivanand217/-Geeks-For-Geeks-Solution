#include<bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *new_node(int data)
{
 struct tree *tmp = (struct tree *)malloc(sizeof(struct tree));
 tmp->data=data;tmp->left=NULL;tmp->right=NULL;
 return tmp;
}

struct tree *insert_(struct tree *root,int data)
{
    if(root==NULL)
    {
        return new_node(data);
    }
    if(root->data > data)
    {
        root->left = insert_(root -> left,data);
    }
    else
    {
        root->right = insert_(root -> right,data);
    }
    return root;
}

// for the second largest node we do a inorder traversal the node which comes second last is the second largest
// here we are doing the reverse inorder traversal then the 2nd element will give the second largest element

void second_largest(struct tree *root,int &c)
{
    // base
    if(root == NULL || c>=2)
    {
        return;
    }
    // follow reverse inorder
    second_largest(root->right,c);
    c++;

    if(c == 2)
    {
        cout<<root->data<<endl;return;
    }
    second_largest(root->left,c);
}

int main()
{
    struct tree *root= NULL;
    root = insert_(root,20);
    insert_(root,10);
    insert_(root,30);
    insert_(root,15);
    insert_(root,19);
    insert_(root,40);
    insert_(root,32);

    int c=0;
    second_largest(root,c);

    return 0;
}
