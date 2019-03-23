#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void append(struct node **root,int data)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));

    tmp->data=data;tmp->next=NULL;
    // if list is empty
    if(*root ==NULL)
    {
        *root=tmp;return;
    }

    struct node *last=*root;
    while(last!=NULL)
    {
        last=last->next;
    }
    last=tmp;
    return;
}

void show(struct node **root)
{
    struct node *tmp=*root;

    while(tmp)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
}

int get_nth(struct node **root,int data)
{
    int count_=0;

    struct node *last=*root;
    while(count_<=data && last)
    {
        if(count_ == data)
        {
            return last->data;
        }
        count_++;
        last=last->next;
    }
}

int main()
{
    struct node *head=NULL;

    append(&head,5);
    append(&head,10);
    append(&head,15);
    append(&head,20);
    append(&head,25);
    append(&head,30);

    show(&head);

    // get nth node of linked list
    // starts with 0
    int get=get_nth(&head,3);
    cout<<3<<"th node is"<<get<<endl;

    return 0;
}
