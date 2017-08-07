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

void solve(struct node *head, struct node **head1, struct node **head2)
{
    struct node *t1 = head; // move this pointer one step at a time
    struct node *t2 = head; // move this pointer two step at a time

    if(head == NULL)
		return;

    while(t2->next != head && t2->next->next != head)
	{
        t1 = t1->next;
        t2 = t2->next->next;
	}
	// even length linked list
    if(t2->next->next == head)
	{
        t2 = t2->next;
	}

    t2->next = t1->next;
    *head2 = t1->next;

    *head1 = head;
    t1->next = *head1;

    return;
}

void printlist(struct node **head)
{
    if(*head == NULL)
		return;

    struct node *tmp = *head;

    while(tmp->next != *head)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;

        if(tmp->next == *head)
			cout<<tmp->data<<endl;
    }
}

int main()
{
    // even length circular LL
    struct node *head = NULL;
    push(&head, 1);
    push(&head, -2);
    push(&head, -3);
    push(&head, 4);

    head->next->next->next->next = head;

    struct node *head1 = NULL;
    struct node *head2 = NULL;

    solve(head, &head1, &head2);//, &head1, &head2);

    cout<<"original list -> ";
    printlist(&head);

	cout<<"splited first half -> ";
	printlist(&head1);

    cout<<"splitted second half -> ";
    printlist(&head2);
	cout<<endl;

	// odd length circular LL
    struct node *head_ref = NULL;
    push(&head_ref, 1);
    push(&head_ref, -2);
    push(&head_ref, -3);
    push(&head_ref, 4);
    push(&head_ref, 7);

    head_ref->next->next->next->next->next = head_ref;
    cout<<"original list -> ";
	printlist(&head_ref);

    struct node *h1 = NULL;
    struct node *h2 = NULL;

    solve(head_ref, &h1, &h2);

    cout<<"splited first half -> ";
	printlist(&h1);

    cout<<"splitted second half -> ";
    printlist(&h2);

    return 0;
}
