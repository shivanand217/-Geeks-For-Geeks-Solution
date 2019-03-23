// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** in unrolled linked list we store various number of elements in eah single node of the linked list, this reduces the memory overhead for the extra pointers
   in the singly linked list , disadvantage is overhead per node is respectively higher than a singly linked list **/

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
#define max_elements 4

struct unrolled
{
    int num_elements;
    int arr[max_elements];
    struct unrolled *next;
};

void print_unrolled_linked_list(struct unrolled *head)
{
    if(head == NULL)
    {
        return;
    }

    while(head!=NULL)
    {
        for(int i=0; i< head->num_elements; i++)
        {
            cout<<head->arr[i]<<" ";
        }cout<<endl;
        head=head->next;
    }
}

int main()
{
    struct unrolled *head=NULL;
    struct unrolled *first=NULL;
    struct unrolled *second=NULL;

   // allocating memory
   head = (struct unrolled *)malloc(sizeof(struct unrolled));
   first = (struct unrolled *)malloc(sizeof(struct unrolled));
   second = (struct unrolled *)malloc(sizeof(struct unrolled));

    head->num_elements=3;
    head->arr[0]=1;
    head->arr[1]=2;
    head->arr[2]=3;

    head->next=first;

    first->num_elements=3;
    first->arr[0]=4;
    first->arr[1]=5;
    first->arr[2]=6;

    first->next=second;

    second->num_elements=3;
    second->arr[0]=7;
    second->arr[1]=8;
    second->arr[2]=9;

    second->next=NULL;
    print_unrolled_linked_list(head);

    return 0;
}
