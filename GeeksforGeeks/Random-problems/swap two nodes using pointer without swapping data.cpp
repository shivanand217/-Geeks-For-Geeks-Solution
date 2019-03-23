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

void swap_(struct node **head, int k1, int k2)
{
    struct node *prev1 = NULL;
    struct node *prev2 = NULL;
    struct node *t1 = *head;
    struct node *t2 = *head;
    struct node *to = *head;

    static int time1 = 0;
    static int time2 = 0;

    while(t1 != NULL)
    {
        if(t1->data == k1)
        {
            break;
        }

        time1++;
        prev1 = t1;
        t1 =  t1->next;
    }

    while(t2 != NULL)
    {
        if(t2->data == k2)
        {
            break;
        }

        time2++;
        prev2 = t2;
        t2 = t2->next;
    }

    if(t1 == NULL || t2 == NULL)
        return;

    struct node *tmp;

    // if t1 is head
    if(prev1 == NULL)
    {
        tmp = t2->next;
        t2->next = t1->next;
        t1->next = tmp;
        prev2->next = t1;
        *head = t2;
        return;
    }

    // if t2 is head
    if(prev2 == NULL)
    {
        tmp = t1->next;
        t1->next = t2->next;
        t2->next = tmp;
        prev1->next = t2;
        *head = t1;
        return;
    }

    // both are adjacent
    if(prev1->next->next->data == k2)
    {
        tmp = t2->next;
        prev1->next = t2;
        t1->next = tmp;
        t2->next = t1;
        *head = to;
        return;
    }

    if(prev2->next->next->data == k1)
    {
        tmp = t1->next;
        prev2->next = t1;
        t2->next = tmp;
        t1->next = t2;
        *head = to;
        return;
    }

    // not adjacent and no one is head
    if(time1 < time2)
    {
        tmp = t2->next;
        t2->next = t1->next;
        t1->next = tmp;
        prev2->next = t1;
        prev1->next = t2;
        *head = to;
        return;
    }

    if(time2 < time1)
    {
        tmp = t1->next;
        t1->next = t2->next;
        t2->next = tmp;
        prev1->next = t2;
        prev2->next = t1;
        *head = to;
        return;
    }

}

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

    /** swap node with value 4 and 10 **/
    swap_(&head, -6, 4); // swapping not adjacent node
    printlist(&head);

    return 0;
}
