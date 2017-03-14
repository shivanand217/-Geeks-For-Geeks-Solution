#include<bits/stdc++.h>
using namespace std;

/** idea is to find the last node of the postorder sequence that is the root of the tree
    then find the index of that in the inorder then call build tree method to
    left and right to that index .. repeat the above steps for each element of the postorder **/

struct node
{
    int data;
    struct node *left,*right;
};

struct node *new_node(int data)
{
  struct node *t=(struct node *)malloc(sizeof(struct node));
 t->data=data;t->left=NULL;t->right=NULL;
return t;
}

// search for the node index
int search_(int in[], int start,int last,int data)
{
    for(int i=start; i<=last; i++)
    {
        if(in[i] == data)
        {
            return i;
        }
    }
}

struct node *buildtree(int post[],int in[], int start, int last)
{
  // base case
 if(start > last)
    return NULL;

 static int postIndex=last;

 struct node *tnode = new_node(post[postIndex]);
 postIndex--;

 //search for index of that data in the inorder
 int i = search_(in, start, last, tnode->data);

 if(start == last)
    return tnode;

  //buildtree on its left and right
  tnode->left = buildtree(post,in,start,i-1);
  tnode->right = buildtree(post,in,i+1,last);

return tnode;
}

void inorder_(struct node *root)
{
    if(!root)
        return;

    inorder_(root->left);
    cout<<root->data<<" ";
    inorder_(root->right);
}

int main()
{
    int post[]={8, 4, 5, 2, 6, 7, 3, 1};
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int len = sizeof(in)/sizeof(in[0]);

    struct node *root=buildtree(post,in,0,len-1);
    inorder_(root);

    return 0;
}
