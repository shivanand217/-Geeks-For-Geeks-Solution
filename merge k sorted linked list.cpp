#include<bits/stdc++.h>
using namespace std;

struct listnode
{
	int data;
	struct listnode *next;
};

// O(m+n+k)

struct listnode *newnode(int val)
{
    struct listnode *tmp = (struct listnode *)malloc(sizeof(struct listnode));
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}

struct listnode *get(struct listnode *h1 ,struct listnode *h2, struct listnode *h3)
{
    struct listnode *mergedlist = NULL;
    struct listnode *c1, *c2, *c3;
    struct listnode *crawl;

    c1 = h1;
    c2 = h2;
    c3 = h3;

    if(c1->data <= c2->data && c1->data <= c3->data)
	{
            mergedlist = newnode(c1->data);
            c1 = c1->next;
	}
	else if(c2->data <= c1->data && c2->data <= c3->data)
	{
			mergedlist = newnode(c2->data);
			c2 = c2->next;
	}
	else if(c3->data <= c1->data && c3->data <= c2->data)
	{
			mergedlist = newnode(c3->data);
			c3 = c3->next;
	}

    crawl = mergedlist;

    while(c1 != NULL && c2 != NULL && c3 != NULL)
	{
        if(c1->data <= c2->data && c1->data <= c3->data)
		{
            crawl->next = newnode(c1->data);
            crawl = crawl->next;
            c1 = c1->next;
		}
		else if(c2->data <= c1->data && c2->data <= c3->data)
		{
			crawl->next = newnode(c2->data);
			crawl = crawl->next;
			c2 = c2->next;
		}
		else if(c3->data <= c1->data && c3->data <= c2->data)
		{
            crawl->next = newnode(c3->data);
            crawl = crawl->next;
            c3 = c3->next;
		}
	}

    if(c1 == NULL)
	{
        while(c2 != NULL && c3 != NULL)
		{
            if(c2->data <= c3->data)
			{
				crawl->next = newnode(c2->data);
                crawl = crawl->next;
                c2 = c2->next;
			}
			else
			{
				crawl->next = newnode(c3->data);
                crawl = crawl->next;
                c3 = c3->next;
			}
		}

        if(c2 == NULL)
		{
            while(c3 != NULL)
			{
                crawl->next = newnode(c3->data);
                crawl = crawl->next;
                c3 = c3->next;
			}
		}
		else if(c3 == NULL)
		{
			while(c2 != NULL)
			{
                crawl->next = newnode(c2->data);
                crawl = crawl->next;
                c2 = c2->next;
			}
		}
	}
	else if(c2 == NULL)
	{
		while(c1 != NULL && c3 != NULL)
		{
            if(c1->data <= c3->data)
			{
				crawl->next = newnode(c1->data);
                crawl = crawl->next;
                c1 = c1->next;
			}
			else
			{
				crawl->next = newnode(c3->data);
                crawl = crawl->next;
                c3 = c3->next;
			}
		}

        if(c1 == NULL)
		{
            while(c3 != NULL)
			{
                crawl->next = newnode(c3->data);
                crawl = crawl->next;
                c3 = c3->next;
			}
		}
		else if(c3 == NULL)
		{
			while(c1 != NULL)
			{
                crawl->next = newnode(c1->data);
                crawl = crawl->next;
                c1 = c1->next;
			}
		}
	}
	else if(c3 == NULL)
	{
		while(c1 != NULL && c2 != NULL)
		{
            if(c2->data <= c1->data)
			{
				crawl->next = newnode(c2->data);
                crawl = crawl->next;
                c2 = c2->next;
			}
			else
			{
				crawl->next = newnode(c1->data);
                crawl = crawl->next;
                c1 = c1->next;
			}
		}

        if(c2 == NULL)
		{
            while(c1 != NULL)
			{
                crawl->next = newnode(c1->data);
                crawl = crawl->next;
                c1 = c1->next;
			}
		}
		else if(c1 == NULL)
		{
			while(c2 != NULL)
			{
                crawl->next = newnode(c2->data);
                crawl = crawl->next;
                c2 = c2->next;
			}
		}
	}

	return mergedlist;
}

void print(struct listnode *mergedlist)
{
    struct listnode *head = mergedlist;

    while(head->next != NULL)
	{
        cout<<head->data<<" ";
        head = head->next;
        if(head->next == NULL)
		{
            cout<<head->data<<" ";
		}
	}
	cout<<endl;
}

int main()
{
	struct listnode *head1 = NULL;
	struct listnode *head2 = NULL;
	struct listnode *head3 = NULL;
	struct listnode *mergedList = NULL;

    head1 = newnode(1);
    head1->next = newnode(10);
    head1->next->next = newnode(20);
    print(head1);

    head2 = newnode(4);
    head2->next = newnode(11);
    head2->next->next = newnode(13);
	print(head2);

    head3 = newnode(3);
    head3->next = newnode(8);
    head3->next->next = newnode(9);
    print(head3);

    mergedList = get(head1, head2, head3);
	print(mergedList);

	return 0;
}
