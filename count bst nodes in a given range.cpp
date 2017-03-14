// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY :O(n+k) // k is the number of the nodes in the given range
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

int cnt_tot=0;

struct tree
{
    int data;
    struct tree *left,*right;
};

struct tree *new_(int data)
{
  struct tree *tmp = (struct tree *)malloc(sizeof(struct tree));

  tmp->data=data;tmp->left=NULL;tmp->right=NULL;
  return tmp;
}

struct tree *insert_(struct tree *root,int data)
{
 if(root == NULL)
 {
     return new_(data);
 }

 if(root->data < data)
 {
     root->right = insert_(root->right , data);
 }
 else
 {
   root->right = insert_(root->left,data);
 }

 return root;
}

int count_node(struct tree *root,int range_l,int range_r)
{
    if(root==NULL)
        return 0;

    if(root->data == range_r && root->data== range_l)
        return 1;

    if(root->data >= range_l && root->data <= range_r)
        return 1+count_node(root->left,range_l,range_r)+count_node(root->right,range_l,range_r);
    else if(root->data < range_l)
        return count_node(root->right,range_l,range_r);
    else
        return count_node(root->left,range_l,range_r);
}


int main()
{
    struct tree *root=NULL;
    root = insert_(root,10);

    insert_(root,20);
    insert_(root,5);
    insert_(root,15);
    insert_(root,21);
    insert_(root,30);
    insert_(root,40);

    int tot=count_node(root,5,15);

    cout<<tot<<endl;
    return 0;
}
