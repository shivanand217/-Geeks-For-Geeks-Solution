#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *next;
};

struct node *newnode(int key)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->key = key;
    tmp->next = NULL;
    return tmp;
}

void push(struct node **head, int key)
{
    if((*head) == NULL)
	{
        (*head = newnode(key));
        return;
	}

	struct node *new_ = (struct node *)malloc(sizeof(struct node));

    struct node *tmp = *head;
    new_->key = key;
    new_->next = NULL;

    while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}

    tmp->next = new_;
    return;
}

void delete_at_position(struct node **head, int pos)
{
    if((*head) == NULL)
		return;

    int p = 0;
    if(pos == 1)
	{
        struct node *tmp = *head;
        (*head) = (*head)->next;
        free(tmp);
        return;
	}
	else
	{
        struct node *tmp = *head;
        struct node *prev = NULL;

        while(1)
		{
            p++;
            if(p == pos || tmp->next == NULL)break;
            prev = tmp;
            tmp=tmp->next;
		}

        if(tmp->next == NULL)
		{
            if(pos != p)
			{
                return;
			}
			else
			{
                prev->next = tmp->next;
                free(tmp);
                return;
			}
		}
		else
		{
            prev->next = tmp->next;
            free(tmp);
		}
	}
}

void print(struct node **head)
{
	struct node *tmp = *head;
	while(tmp != NULL)
	{
        printf("%d ", tmp->key);
        tmp = tmp->next;
	}
}

int main()
{
    struct node *head = NULL;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 1);
    push(&head, 3);

    print(&head);
    putchar('\n');

    delete_at_position(&head, 5);
    print(&head);

    return 0;
}
