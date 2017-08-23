#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right, *right_next;
};

struct node *newnode(int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->right_next = NULL;
    return tmp;
}

void connect_nodes_at_same_level(deque<pair<struct node *, int> > qu)
{
    int prev = 0;
    pair<struct node *, int> p1, p2;

    while(!qu.empty())
	{
        if(prev == p.second)
		{
            cout<<p.first->data<<" ";
		}
		else
		{
            cout<<endl;
            cout<<p.first->data<<" ";
		}

        prev = p.second;

        if(p.first->left != NULL)
		{
			qu.push_back(make_pair(p.first->left, p.second+1));
		}

		if(p.first->right != NULL)
		{
            qu.push_back(make_pair(p.first->right, p.second+1));
		}
	}

	while(!qu.empty())
	{
		p1 = qu.front();
        qu.pop_front();

        if(qu.empty())
		{
            break;
		}

		p2 = qu.front();
        qu.pop_front();

        if(p1.second == p2.second)
		{
            p1.first->right_next = p2.first;
		}

		qu.push_front(p2);
	}
}

int main()
{

}

