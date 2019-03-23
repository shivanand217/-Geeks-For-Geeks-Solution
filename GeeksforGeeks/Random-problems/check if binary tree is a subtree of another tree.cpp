// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(max(n,m))
// SPACE COMPLEXITY : O(sizeof(tree1) + sizeof(tree2))

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

/** idea is to we do the inorder of both the tree
    and store in the string
    now we check whether the smallest length string is present in the
    other string **/

string fir="";
string sec="";

struct node
{
    char key;
    struct node *left,*right;
};

struct node *newnode(char key)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->key = key;
    tmp->left=NULL;
    tmp->right = NULL;
    return tmp;
}

void in_root1(struct node *root)
{
    if(!root)
        return;
    in_root1(root->left);
    fir+=root->key;
    in_root1(root->right);
}

void in_root2(struct node *root)
{
    if(!root)
        return;
    in_root2(root->left);
    sec+=root->key;
    in_root2(root->right);
}

bool check_ans()
{
    if(fir.length() > sec.length())
    {
        for(int i=0; i<fir.length(); i++)
        {
            if(fir.substr(i,sec.length()) == sec)
                return true;
        }
        return false;
    }
    else
    {
        for(int i=0; i<sec.length(); i++)
        {
            if(sec.substr(i,fir.length()) == fir)
                return true;
        }
        return false;
    }
}

int main(){

struct node *root=NULL;

root = newnode('A');
root->right = newnode('F');
root->right->right = newnode('G');
root->left = newnode('B');
root->left->left = newnode('C');
root->left->left->right = newnode('D');
root->left->right = newnode('E');

struct node *root2=NULL;

root2 = newnode('B');
root2->left = newnode('C');
root2->left->right = newnode('D');
root2->right = newnode('E');

in_root1(root);
in_root2(root2);

if(check_ans())
    cout<<"present"<<endl;
else
    cout<<"not present"<<endl;

return 0;
}
