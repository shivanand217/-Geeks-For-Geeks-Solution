// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(nlogn)

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int height;
    struct node *left,*right;
    int size_;
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

int get_size(struct node *root)
{
    if(!root)
        return 0;
    return root->size_;
}

struct node *newnode(int data)
{
 struct node *tmp = (struct node *)malloc(sizeof(struct node));
 tmp->data=data;
 tmp->left=NULL;tmp->right=NULL;
 tmp->height = 1;
 tmp->size_= 0;
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

// assuming no duplicates is added
struct node *_insert(struct node *root,int data, int *result)
{
    if(root==NULL)
    {
        return(newnode(data));
    }
    if(data < root->data)
    {
        root->left = _insert(root->left, data, result);
        *result = *result + get_size(root->right) + 1;
    }
    else
    {
        root->right = _insert(root->right, data, result);
    }
    /** in case a duplicate no insertion happened
    return node **/

    // updating the heights
    root->height = max(height(root->left),height(root->right)) + 1;
    root->size_ = get_size(root->left) + get_size(root) + 1;
    int balance = get_balance(root);

    // for left left case
    if(balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    if(balance < -1 && data > root->right->data)
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

int get_inversion_count(int arr[],int size_)
{
    struct node *root = NULL; //empty avl tree

    int result = 0;
    for(int i=0; i<size_; i++)
    {
        root = _insert(root, arr[i], &result);
    }
    return result;
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,-1};
    int size_ = sizeof(arr)/sizeof(arr[0]);

    int result = get_inversion_count(arr,size_);
    cout<<result<<endl;

    //inorder(root);
    return 0;
}
