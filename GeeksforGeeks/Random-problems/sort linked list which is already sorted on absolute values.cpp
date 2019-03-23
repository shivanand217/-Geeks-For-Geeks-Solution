#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *newnode(int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));

    tmp->data = data;
    tmp->next = NULL;

    return tmp;
}

void push(struct node **head, int data)
{
     if((*head) == NULL)
     {
        (*head) = newnode(data);
        return;
     }

     struct node *new_ = new struct node;
     new_->data = data;
     new_->next = NULL;

     struct node *tmp = *head;

     while(tmp->next != NULL)
     {
        tmp = tmp->next;
     }

     tmp->next = new_;

     return;
}

void printlist(struct node **head)
{
    struct node *tmp = *head;

    while(tmp != NULL)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }cout<<endl;
}

void solve(struct node **head)
{
    // whenever we get a negative node insert it to the front of the list
    struct node *tmp = *head;
    struct node *alone;
    struct node *prev = NULL;

    while(tmp != NULL)
    {
        if(tmp->data < 0)
        {
            if(prev != NULL)
            {
                prev->next = prev->next->next;
                alone = tmp;
                int val = tmp->data;
                tmp=tmp->next;
                free(alone);

                struct node *new_ = new struct node;
                new_->data = val;
                new_->next = *head;
                *head = new_;
            }
        }
        else
        {
            prev = tmp;
            tmp = tmp->next;
        }
    }

    return;
}

/** input
        1 -> -2 -> -3 -> 4 -> -5

    output
        -5 -> -3 -> -2 -> 1 -> 4
**/

int main()
{
    struct node *head = NULL;

    push(&head, 1);
    push(&head, -2);
    push(&head, -3);
    push(&head, 4);
    push(&head, 5);
    push(&head, -6);
    push(&head, -7);
    push(&head, -8);
    push(&head, 10);

    printlist(&head);

    solve(&head);

    printlist(&head);

    return 0;
}
