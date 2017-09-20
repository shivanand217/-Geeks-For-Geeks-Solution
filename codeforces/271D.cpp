#include<bits/stdc++.h>
using namespace std;

int ans = 0;
unordered_map<int, int> un;

struct node
{
    bool isLeaf;

    struct node *next[26];

    node()
    {
        isLeaf = false;

        for(int i=0; i<26; i++)
		{
            next[i] = NULL;
		}
    }
};

struct node *trie_root;

void insert_(string str, int len, int k)
{
    struct node *curr = trie_root;

    int id;
    int tot = 0;

    for(int i=0; i < len; i++)
	{
		id = str[i] - 'a';

        if(un[id] == 0)
            tot++;

        if(curr->next[id] == NULL)
		{
            if(tot <= k)
				ans++;

			curr->next[id] = new struct node;
		}

        curr = curr->next[id];
	}

    curr->isLeaf = true;
}

void del(struct node *root)
{
    for(int i=0; i<26; i++)
	{
          if(root->next[i] != NULL)
		  {
                del(root->next[i]);
		  }
	}
    delete root;
}


int main()
{
    string ss, st;
	cin>>ss;

    int k;

    string p;
    cin>>p;

    for(int i=0; i<p.length(); i++)
	{
        un[i] = p[i] - '0';
	}

    cin>>k;

	trie_root = new struct node;

    for(int i=0 ; i < ss.length(); i++)
	{
        st = ss.substr(i);
        insert_(st, st.length(), k);
	}

    cout<<ans<<endl;
    del(trie_root);

	return 0;
}

