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

void insert_(string str)
{
    struct node *curr = trie_root;

    int id;

    for(int i=0; i<str.length(); i++)
	{
        id = str[i] - 'a';

        if(curr->next[id] == NULL)
		{
			curr->next[id] = new struct node;
		}

		curr = curr->next[id];
	}

    curr->isLeaf = true;
}

void search_(string sn, vector<string>& ans, int index, struct node *curr, string str)
{
    if(index > sn.length()-1)
	{
        if(curr->isLeaf == true && str != sn)
		{
            ans.push_back(str);
		}

        for(int i=0; i < 26; i++)
		{
            if(curr->next[i] != NULL)
			{
                char c = i + 'a';

                search_(sn, ans, index, curr->next[i], str+c);
			}
		}
	}
	else
	{
        int id = sn[index] - 'a';

        if(curr->next[id] != NULL)
		{
            char c = sn[index];

            search_(sn, ans, index+1, curr->next[id], str+c);
		}
	}

    return;
}

int main()
{
    int n, k;
    cin>>n;
    string s , sn;
    trie_root = new struct node;

	while(n--)
    {
        cin>>s;
        insert_(s);
	}

    cin>>k;

    for(int j=1; j<=k; j++)
	{
        cin>>sn;

        vector<string> ans;

        search_(sn, ans, 0, trie_root, "");

        cout<<"Case #"<<j<<":"<<endl;

        for(int i=0; i<ans.size(); i++)
		{
            cout<<ans[i]<<endl;
		}

        if(ans.size() == 0)
		{
            cout<<"No match."<<endl;
		}
	}

	return 0;
}
