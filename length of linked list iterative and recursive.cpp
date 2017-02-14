// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

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
		cout<<"data not present!!"<<endl;return;
	}
	else
	{
		prev->next=tmp->next;
		free(tmp);
		return;
	}
}

int length_iter(struct node **root)
{
    int count_=0;

    struct node *last=*root;

    while(last!=NULL)
    {
        count_++;
        last=last->next;
    }
    return count_;
}

int length_recursive(struct node **root)
{
    struct node *tmp=*root;

    if(tmp==NULL)
        return 0;
    else
    {
        return 1+length_recursive(&(tmp->next));
    }
}

// print the list
void show(struct node **root)
{
	struct node *last=*root;

	while(last!=NULL)
	{
		cout<<last->data<<" ";
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
	cout<<endl;

	int length_iterative = length_iter(&head);
	int length_recur = length_recursive(&head);

	cout<<length_iterative<<endl;
	cout<<length_recur<<endl;

	//show(&head);
	return 0;
}
