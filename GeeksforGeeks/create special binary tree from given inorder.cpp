/** time = O(n*n) **/

/** idea is to pick the maximum element in the interval make that the root node
    ans then call the buildtree to its left and right then make that leftsubtree and rightsubtree respectively
    **/

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

int max_(int inorder[],int l,int r)
{
    int max_ele=0,max_ind;

    for(int i=l; i<=r; i++)
    {
        if(max_ele < inorder[i])
        {
            max_ele = inorder[i];
            max_ind = i;
        }
    }
    return max_ind;
}

struct node *new_node(int data)
{
struct node *t = (struct node*)malloc(sizeof(struct node));
t->data=data;
t->left=NULL;t->right=NULL;
return t;
}

struct node *buildtree(int inorder[], int start, int end_)
{
  //base case
  if(start > end_)
    return NULL;

 // first we find the maximum index in the interval
 int i = max_(inorder, start, end_);

 // make that as root
 struct node *root = new_node(inorder[i]);

 // if that is leaf node then return
 if(start == end_)
    return root;

 // otherwise go and do the same in the left and right
 root->left = buildtree(inorder, start,i-1);
 root->right = buildtree(inorder, i+1, end_);

 return root;
}

//perform the inorder of that builded tree
void inorder_(struct node *root)
{
    if(!root)return;

    inorder_(root->left);
    cout<<root->data<<" ";inorder_(root->right);
}

int main()
{
    int inorder[] = {5,10,40,30,20};
    int len = sizeof(inorder)/sizeof(inorder[0]);

    struct node *root = buildtree(inorder, 0 ,len-1);

    inorder_(root);
    return 0;
}
