#include<bits/stdc++.h>
using namespace std;

struct treenode
{
    int data;
    struct treenode *left, *right;
};

struct treenode *newnode(int data)
{
    struct treenode *tmp = (struct treenode *)malloc(sizeof(struct treenode));
    tmp->data = data;

    tmp->left = tmp->right = NULL;

    return tmp;
}

void inorder(struct treenode *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    return;
}

// converting while traversing in in_order fashion

void solve(struct treenode *root, struct treenode **head)
{
    if(root == NULL)
    {
        return;
    }

    static struct treenode *prev = NULL;

    solve(root->left, head);

    if(prev == NULL)
    {
        (*head) = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }

    prev = root;

    solve(root->right, head);

    return;
}

void print_DLL(struct treenode **head)
{
    if(*head == NULL)
        return;

    struct treenode *DLL = *head;

    while(DLL != NULL)
    {
        cout<<DLL->data<<" ";
        DLL = DLL->right;
    }

    cout<<endl;
}

int main()
{
    struct treenode *root = NULL;

    root = newnode(10);
    root->left = newnode(12);
    root->left->left = newnode(25);
    root->left->right = newnode(30);
    root->right = newnode(15);
    root->right->left = newnode(36);

    //in_order(root);

    struct treenode *head = NULL;

    solve(root, &head);

    print_DLL(&head);

    return 0;
}
