#include<bits/stdc++.h>
using namespace std;

/** idea is that we pick the first element from the preorder
    increment the preorder index
    then we find the index of that node in the inorder sequence
    then recursively call the buildtree on its left and right side
    finally return the builded tree **/

struct node {
char data;
struct node *left,*right;

};

struct node *new_node(char data)
{
 struct node *t=(struct node *)malloc(sizeof(struct node));
 t->data=data;t->left=NULL;t->right=NULL;
 return t;
}

// search for the index
int search_(char in[],int start,int last,char data)
{
    for(int i=start; i<=last; i++)
    {
        if(in[i] == data)
            return i;
    }
}

// buildtree method
struct node *buildtree(char pre[],char in[], int start, int last)
{
 // make the index of preorder static
 static int indPreorder = 0;

 // base case
 if(start > last)
    return NULL;

 struct node *tnode = new_node(pre[indPreorder]);
indPreorder++;
 // then find the index of that node in the inorder
 int i = search_(in, start, last, tnode->data);

 if(start == last)
    return tnode;

 // otherwise call the buildtree on its left and right subpart
 tnode->left = buildtree(pre,in, start,i-1);
 tnode->right = buildtree(pre,in, i+1, last);

return tnode;

}

// inorder of the builded tree
void inorder_(struct node *root)
{
    if(!root)return;
    inorder_(root->left);

    cout<<root->data<<" ";inorder_(root->right);
}

int main()
{
    /**D B E A F C
Preorder sequence: A B D E C F**/
    char pre[]={'A' ,'B' ,'D' ,'E' ,'C' ,'F'};
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};

    int len = sizeof(pre)/sizeof(pre[0]);

    struct node *root = buildtree(pre,in,0,len-1);

inorder_(root);
return 0;
}
