#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left ,*right, *next; // next points to inorder successor
};

struct node *newnode(int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->next = NULL;
    return tmp;
}

void inorder(struct node *root)
{
	if(root == NULL)
		return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

	return;
}

void solve(struct node *root)
{
    vector<struct node *> ans;
	stack<struct node *> st;

	if(root == NULL)
		return;

	st.push(root);
	root = root->left;

        while(root != NULL)
        {
            st.push(root);
            root = root->left;
        }

	struct node *tmp;

	while(!st.empty())
	{
            tmp = st.top();
            st.pop();
            ans.push_back(tmp);

            if(tmp->right != NULL)
            {
                st.push(tmp->right);

                tmp = tmp->right;
                tmp = tmp->left;

                while(tmp != NULL)
                {
                    st.push(tmp);
                    tmp = tmp->left;
                }
            }
	}

    for(int i=0; i < ans.size()-1; i++)
	{
        ans[i]->next = ans[i+1];
	}

	ans[ans.size()-1]->next = NULL;
}

void solved_inorder_successor(struct node *root)
{
    if(root->next == NULL)
	{
		cout<<"inorder successor of "<<root->data<<" is -1"<<endl;
        return;
	}

    cout<<"inorder successor of "<<root->data<<" is "<<root->next->data<<endl;
    solved_inorder_successor(root->next);
    return;
}

int main()
{
	struct node *root = NULL;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->right = newnode(4);
    root->left->right->right = newnode(5);
    root->left->right->right->right = newnode(6);

	inorder(root);

		cout<<endl;
		solve(root);

    solved_inorder_successor(root->left);

    return 0;
}
