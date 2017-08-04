#include<bits/stdc++.h>
using namespace std;

struct node
{
    string data;
    struct node *next;
};

struct node *newnode(string data)
{
    struct node *tmp = new struct node;

    tmp->data = data;
    tmp->next = NULL;

    return tmp;
}

void push(struct node **head, string data)
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

string printlist(struct node **head)
{
    struct node *tmp = *head;
    string str = "";

    while(tmp != NULL)
    {
        cout<<tmp->data<<" ";
        str += tmp->data;
        tmp = tmp->next;
    }cout<<endl;

    return str;
}

/**
    input
        a -> bc -> d -> dcb -> a -> NULL
    output
        abcddcba is a palindrome
**/

bool isPalin(string ans)
{
    int i=0;
    int j= ans.length() - 1;

    while(i < j)
    {
        if(ans[i] != ans[j])
            return false;

        i++;
        j--;
    }

    return true;
}

bool solve(string data)
{
    if(isPalin(data))
    {
        return true;
    }

    return false;
}


int main()
{
    struct node *head = NULL;

    push(&head, "a");
    push(&head, "bc");
    push(&head, "d");
    push(&head, "dcb");
    push(&head, "a");
    //push(&head, "ababa");

    string str = printlist(&head);

    if(solve(str))
    {
        cout<<str<<" is a palindrome"<<endl;
    }
    else
    {
        cout<<str<<" is not a palindrome"<<endl;
    }

    return 0;
}
