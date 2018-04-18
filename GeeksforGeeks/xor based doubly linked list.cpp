// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY :
// SPACE COMPLEXITY :

/** we have used xor based doubly linked list because it decreases the overhead of pointers for the both previous and next
    we use only one pointer at each node that is the xor value of pointer of previus and the next value at each node **/

/** we are only inserting the node at the begining of the list **/

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

struct xor_dll
{
    int data;
    struct xor_dll *next; // this next pointer stores xor of the next and previous of the node
};

struct xor_dll * XOR(struct xor_dll *a,struct xor_dll *b)
{
   return (struct xor_dll*)((unsigned int)a ^ (unsigned int)b);
}

void insert_node_at_begining(struct node **head,int data) // this head is reference to the head of the main function means it updates the local variable of one function into other function
{
    // allocate memory to the new node
    struct xor_dll *tmp = (struct xor_dll *)malloc(sizeof(struct xor_dll));
    tmp->data=data;

    tmp->next = XOR(*head,NULL);

    /* If linked list is not empty, then next of current head node will be XOR
       of tmp node and node next to current head */

    if(head!=NULL)
    {
        struct xor_dll *next_ = XOR((*head)->next,NULL ); // kyonki ab head ka next change karna hoga because uska previous ab NULL nahi hai
        (*head)->next = XOR(tmp,next);
    }
    // update head
    *head = tmp;
}

void print(struct xor_dll **head)
{
    struct xor_dll *prev=NULL;
    struct xor_dll *curr=head;
    struct xor_dll *next;

    printf("xor based linked list: \n");

    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        //now curr->next is next^prev so curr->next^prev is next^prev^prev which is next
        next = XOR(prev,curr->next);

        // update the remain
        prev=curr; // now new previous should be the current
        curr=next; // and current will be the next of last
    }
}

int main()
{

struct xor_dll *head=NULL;

insert_node_at_begining(&head,10);
insert_node_at_begining(&head,20);
insert_node_at_begining(&head,30);

print(&head);

return 0;
}
