#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left ,*right;
};

struct node *newnode(int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
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

int tree_height1, tree_height2;

int height(struct node *root)
{
    if(root == NULL)
	{
		return 0;
	}

	return (1 + max(height(root->left), height(root->right)));
}

void leaf_level_traversal(struct node *root, vector<int>& vec, int level , bool flag)
{
	if(flag == true)
	{
        if(level == tree_height1 || root == NULL)
		{
			return;
		}
        if(level == tree_height1-1)
		{
            if(root->left != NULL)
			{
				vec.push_back(root->left->data);
			}

			if(root->right != NULL)
			{
                vec.push_back(root->right->data);
			}
		}
		else
		{
            leaf_level_traversal(root->left, vec, level+1, flag);
            leaf_level_traversal(root->right, vec, level+1, flag);
		}
	}
	else
	{
		if(level == tree_height2 || root == NULL)
		{
			return;
		}
        if(level == tree_height2-1)
		{
            if(root->left != NULL)
			{
				vec.push_back(root->left->data);
			}

			if(root->right != NULL)
			{
                vec.push_back(root->right->data);
			}
		}
		else
		{
            leaf_level_traversal(root->left, vec, level+1, flag);
            leaf_level_traversal(root->right, vec, level+1, flag);
		}
	}

	return;
}

int main()
{
	  struct node *root1 = newnode(1);
      root1->left = newnode(2);
      root1->right = newnode(3);
      root1->left->left = newnode(4);
      root1->right->left = newnode(6);
      root1->right->right = newnode(7);

      struct node *root2 = newnode(0);
      root2->left = newnode(1);
      root2->right = newnode(5);
      root2->left->right = newnode(4);
      root2->right->left = newnode(6);
      root2->right->right = newnode(7);

      tree_height1 = height(root1);
      tree_height2 = height(root2);

      vector<int> vec1, vec2;

	  leaf_level_traversal(root1, vec1, 1, true);
      leaf_level_traversal(root2, vec2, 1, false);

      for(int i=0; i<vec1.size(); i++)
	  {
	  	cout<<vec1[i]<<" ";
	  }cout<<endl;

      for(int i=0; i<vec2.size(); i++)
	  {
        cout<<vec2[i]<<" ";
	  }cout<<endl;

      if(vec1.size() != vec2.size())
	  {
        cout<<"not same"<<endl;
	  }
	  else
	  {		int i;

            for(i=0; i<vec1.size(); i++)
			{
                if(vec1[i] != vec2[i])
                {
                    break;
                }
			}

			if(i == vec1.size())
			{
                cout<<"same"<<endl;
			}
			else
			{
                cout<<"not same"<<endl;
			}
	  }

	return 0;
}
