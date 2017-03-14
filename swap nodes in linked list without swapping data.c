// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

#include<stdio.h>
#include<stdlib.h>
//using namespace std;

struct node
{
  int data;
  struct node *next;
};

/** assuming that no duplicates present in the list **/

// push data at begining
void push(struct node **root, int data)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));

	tmp->data=data;
	tmp->next=NULL;

	if(*root == NULL)
	{
		*root=tmp;
		return;
	}
	else
	{
		tmp->next=*root;
		*root=tmp;
		return;
	}
}

// append data to the end
void append(struct node **root,int data)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));

	tmp->data=data; tmp->next=NULL;
	struct node *last=*root;

	if(*root == NULL)
	{
		*root=tmp;
	    return;
	}

	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=tmp;
	return;
}

// push after any particular node
void insert_after(struct node **root,int data,int new_)
{
	struct node*curr = *root;
	while(curr->data != data)
	{
		curr=curr->next;
	}

	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=new_;
	tmp->next=curr->next;
	curr->next=tmp;
	return;
}

// find the previous of the node to be deleted
// change the next of the previous
// free() the node

void delete_node(struct node **root,int data)
{
	struct node *tmp=*root;
	struct node *prev=*root;

    // if first node data is the data
    if(tmp!=NULL && tmp->data==data)
    {
    	*root=tmp->next;
    	free(tmp);
    	return;
    }

	while(tmp->data!=data && tmp!=NULL)
	{
		prev=tmp;
		tmp=tmp->next;
	}
	// if the data is not present

	if(tmp == NULL || tmp->data != data)
	{
		//cout<<"data not present!!"<<endl;return;
	}
	else
	{
		prev->next=tmp->next;
		free(tmp);
		return;
	}
}

void swap_nodes_without_swapping_data(struct node **root,int data1,int data2)
{
    struct node *prev1=NULL;
    struct node *prev2=NULL;
    struct node *tmp=*root;

    // we have to check if both are present in the node
    while(tmp)
    {
        if(tmp->next && tmp->next->data==data1)
        {
            prev1=tmp;
        }
        if(tmp->next && tmp->next->data==data2)
        {
            prev2=tmp;
        }
        tmp=tmp->next;
    }

    // check if both node is present and both is at between head and tail
    if(prev1 && prev2)
    {
        // then we have to swap only next to these nodes
        // if both are adjacent
        struct node *tmp=prev1->next;
        struct node *tmp2=prev2->next->next;
        if(prev1->next->next->data == data2)
        {
            prev1->next=prev1->next->next;
            tmp->next=prev2->next->next;
            tmp=prev1->next;
            tmp->next=
        }
    }
    else if(!prev && prev2)
    {

    }
    else if(prev1 && !prev2)
    {

    }
    else
    {
        // checking for the presence at both front and the last
    }
}

// print the list
void show(struct node **root)
{
	struct node *last=*root;

	while(last!=NULL)
	{
		printf("%d ",last->data);
		last=last->next;
	}
}

int main()
{
	struct node *head = NULL;

	append(&head,4);
	push(&head,5);
	push(&head,7);
	push(&head,8);
	append(&head,11);
	append(&head,10);
	append(&head,20);
	append(&head,25);
	append(&head,30);
	insert_after(&head,8,25);

	show(&head);
	printf("\n");

	return 0;
}
