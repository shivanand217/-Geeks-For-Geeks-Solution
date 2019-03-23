// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(logn)

#include<bits/stdc++.h>
using namespace std;

/** in avl tree deletion we can perform standard avl deletion with the rotation required for balancing the tree **/

struct node
{
    int data;
    int height;
    int count_;
    struct node *left,*right;
};

int height(struct node *r)
{
    if(r==NULL)
        return 0;
    else return r->height;
}

int get_balance(struct node *root)
{
    return (height(root->left) - height(root->right));
}

struct node *newnode(int data)
{
 struct node *tmp = (struct node *)malloc(sizeof(struct node));
 tmp->data=data;
 tmp->left=NULL;tmp->right=NULL;
 tmp->height = 1;
 tmp->count_ = 1;
 return tmp;
}

struct node *rightRotate(struct node *x)
{
  struct node *m = x->left;
  struct node *n = x->left->right;

  // rotate
  m->right = x;
  x->left = n;
  // updating the heights
  x->height = max(height(x->left), height(x->right))+1;
  m->height = max(height(m->left), height(m->right))+1;
  // m is the new root
  return m;
}

struct node *leftRotate(struct node *x)
{
  struct node *t = x->right;
  struct node *t1 = x->right->left;

  //rotate
  x->right = t1;
  t->left = x;

  //update heights
  x->height = max(height(x->left), height(x->right))+1;
  t->height = max(height(t->left), height(t->right))+1;
  // t is the new root
  return t;
}

struct node *lowest_inorder_succesor(struct node *root)
{
   struct node *tmp = root->right;

   while(tmp->left!=NULL)
   {
       tmp = tmp->left;
   }
   return tmp;
}

// assuming no duplicates is added
struct node *_insert(struct node *root,int data)
{
    if(root==NULL)
    {
        return(newnode(data));
    }
    if(data < root->data)
    {
        root->left = _insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = _insert(root->right, data);
    }
    else // for duplicates
    {
        root->count_++;
        return root;
    }
    /** in case a duplicate no insertion happened
    return node **/

    // updating the heights
    root->height = 1+max(height(root->left),height(root->right));
    int balance = get_balance(root);

    // for left left case
    if(balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    if(balance < -1 && data >root->right->data)
    {
        return leftRotate(root);
    }
    if(balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

struct node *_delete(struct node *root,int data)
{
    // node is not present in the tree
    if(root==NULL)
    {
        return root;
    }

   if(root->data > data)
   {
       root->left = _delete(root->left,data);
   }
   else if(root->data < data)
   {
       root->right = _delete(root->right, data);
   }
   else // if the node matches
   {
       // check if the count of that node is zero or not
       if(root->count_ > 1)
       {
           root->count_-=1;
           return root;
       }
       else
       {
       if(root->right == NULL || root->left == NULL)
       {
           struct node *tmp = root->right?root->right:root->left;

           //no child case
           if(tmp == NULL)
           {
               tmp = root;
               root=NULL;
           }
           else // one child case
           {
               *root = *tmp;
               /** or we can do root->data = tmp->data  then free(tmp) **/
           }
           free(tmp);
       }
       else /** get the inorder successor and update root **/
       {
           struct node *tmp = lowest_inorder_succesor(root);
           root->data = tmp->data;
           root->right = _delete(root->right,tmp->data);
       }
       }
   }
   // if only one node
   if(!root)
   {
       return root;
   }

   // update the heights
   root->height = max(height(root->left),height(root->right));
   int balance = get_balance(root);

    // for left left case
    if(balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    if(balance < -1 && data >root->right->data)
    {
        return leftRotate(root);
    }
    if(balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<"{ "<<root->data<<" "<<root->count_<<" }, ";
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    root = _insert(root,10);
    root = _insert(root,20);
    root = _insert(root,30);
    root = _insert(root,40);
    root = _insert(root,50);
    root = _insert(root,25);
    root = _insert(root,50);
    root = _insert(root,25);
    inorder(root);

    cout<<endl<<endl;
    root = _delete(root,50);
    inorder(root);
    cout<<endl<<endl;
    root = _delete(root,40);
    inorder(root);

    return 0;
}
