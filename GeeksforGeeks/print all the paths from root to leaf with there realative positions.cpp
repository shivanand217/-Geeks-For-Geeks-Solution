// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n) // n is number of nodes
// SPACE COMPLEXITY : O(max_path)

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define LL long long
#define mod 1000000007
using namespace std;
#define max_path_size 1000

struct node
{
    char data;
    struct node *left,*right;
};

struct node *insert_(char data)
{
   struct node *root =(struct node *)malloc(sizeof(struct node));
   root->data=data;
   root->left=NULL;root->right=NULL;
   return root;
}

struct PATH
{
    int hd;
    char key;
};

void inorder(struct node *root)
{
    if(!root)
        return;
    inorder(root->left);
    //cout<<root->data<<" "<<HD[root->data]<<endl;
    inorder(root->right);
}

void print_path(vector<PATH> path,int size_path)
{

// find the minimum horizontal distance in the pathr
int minimum_hd=INT_MAX;

for(int i=0; i<size_path; i++)
{
    if(path[i].hd < minimum_hd)
        minimum_hd = path[i].hd;
}

int underscore;
for(int i=0; i<size_path; i++)
{
    underscore = abs(path[i].hd - minimum_hd);
    for(int j=0; j<underscore; j++)
    {
        cout<<"_ ";
    }
    cout<<path[i].key<<endl;
}

cout<<"****"<<endl;
}

void print_path_util(struct node *root,vector<PATH> &allpath,int hd,int order)
{
    if(!root)
        return;
    // if leaf node then print the path
    if(root->left==NULL && root->right == NULL)
    {
        allpath[order] = PATH{hd,root->data};
        print_path(allpath,order+1);
        return;
    }

    // otherwise store the current path
    allpath[order] = PATH{hd,root->data};

    // left subtree
    print_path_util(root->left, allpath, hd-1, order+1);

    //right subtree
    print_path_util(root->right, allpath, hd+1, order+1);
}

void print_all_path(struct node *root)
{
    // if root is NULL
    if(!root)
        return;

    vector< PATH > allpath(max_path_size);
    print_path_util(root,allpath,0,0);
}

int main()
{
    struct node *root=NULL;

    root=insert_('A');

    root->right=insert_('C');
    root->left = insert_('B');
    root->right->right = insert_('F');
    root->left->left = insert_('D');
    root->left->right = insert_('E');

    print_all_path(root);

  //  inorder(root);

return 0;
}
