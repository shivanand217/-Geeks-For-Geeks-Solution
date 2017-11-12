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
#define pi printf("YES\n")
#define po printf("NO\n")
#define p(x) scanf("%d", &x)

int ans;

struct node
{
	bool isLeaf;
    struct node *next[10];

    node()
    {
        isLeaf = false;

        for(int i=0; i<10; i++)
		{
            next[i] = NULL;
		}
    }

} *trie_root ;

void insert_(string s, struct node *curr)
{
    int id;

    for(int i=0; i < s.length(); i++)
	{
        id = s[i] - '0';

        if(curr->next[id] == NULL)
		{
            curr->next[id] = new struct node;
		}

        if(curr->isLeaf == true)
		{
            ans = 1;
		}
        curr = curr->next[id];
	}

    if(curr->isLeaf == true)
	{
        ans = 1;
	}

    curr->isLeaf = true;
}

void del(struct node *root)
{
    for(int i=0; i<10; i++)
	{
        if(root->next[i])
			del(root->next[i]);
	}

    delete root;
}

bool compp(string s1, string s2)
{
    return (s1.length() < s2.length());
}

string phone_list[10005];

int main()
{
    int t;
    p(t);

    int n;
    string s;

    while(t--)
	{
        trie_root = new struct node;

        p(n);
        ans = 0;

        for(int i=0; i<n; i++)
		{
            cin>>phone_list[i];
		}

        sort(phone_list, phone_list+n, compp);

        for(int i=0; i<n; i++)
		{
            insert_(phone_list[i], trie_root);
		}

         if(ans == 1)
            po;
		 else
            pi;

         del(trie_root);
	}

    return 0;
}
