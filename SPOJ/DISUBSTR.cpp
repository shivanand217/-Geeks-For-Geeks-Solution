#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define fck std::ios::sync_with_stdio(false);
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

int tot;

struct node
{
    bool isLeaf;
    struct node *next[52];

    node()
    {
        isLeaf = false;

        for(int i=0; i<52; i++)
		{
            next[i] = NULL;
		}
    }
};

struct node *trie_root;

void insert_(string str, int len)
{
    struct node *curr = trie_root;

    int id;

    for(int i=0; i < len; i++)
	{
        if(str[i] >= 'a' && str[i] <= 'z')
			id = str[i] - 'a';
        else
			id = str[i] - 'A' + 26;

        if(curr->next[id] == NULL)
		{
			curr->next[id] = new struct node;
            tot++;
		}

        curr = curr->next[id];

	}

    curr->isLeaf = true;
}

void del(struct node *root)
{
    for(int i=0; i<52; i++)
	{
          if(root->next[i] != NULL)
		  {
                del(root->next[i]);
		  }
	}

    delete root;
}
char s[100005];

int main()
{
	int t , le;
	scanf("%d", &t);
    string ss, st;

    while(t--)
	{
        trie_root = new struct node;
        scanf("%s", s);
		tot = 0;
        st = s;
        for(int i=0; i < st.length(); i++)
		{
            ss = st.substr(i);
            insert_(ss, ss.length());
		}
        printf("%d\n", tot);
        del(trie_root);
	}

	return 0;
}
