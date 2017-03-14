#include<bits/stdc++.h>
using namespace std;

#define CHAR_TO_INT(c) ((int)c-(int)'a')

#define FREE(p) \
    free(p);    \
    p = NULL;

struct trie
{
    struct trie *child[26]; //we are only considering the alphabet from a to z
    bool is_leaf;
};

// create a new trienode

struct trie *new_node()
{
 struct trie *new_= NULL;

 new_ = (struct trie *)malloc(sizeof(struct trie));
 new_->is_leaf = false;

 for(int i=0; i<26; i++)
 {
     new_->child[i]=NULL;
 }

 return new_;
}

struct trie *insert_(struct trie *root,string s)
{
    int index;
    struct trie *p=root;

    for(int i=0; i<s.length(); i++)
    {
        index = CHAR_TO_INT(s[i]);

        if(p->child[index]==NULL)
        {
            p->child[index] = new_node(); // then creatre new empty trie node to that character because that character is present in the node
        }
        p = p->child[index];
    }

    // mark the present node as the leaf node because this string is present in the node
    p->is_leaf = true;
}

bool search_(struct trie *root,string s)
{
 int index;
 struct trie *p=root;

 for(int i=0; i<s.length(); i++)
 {
     index = CHAR_TO_INT(s[i]);

     if(p->child[index] == NULL)
     {
         return false;
     }
     p=p->child[index];
 }

 if(p==NULL || p->is_leaf==false)
    return false;
 else
    return true;

}

int main()
{
    struct trie *root =new_node();

    int q;cin>>q;

    string s;
    while(q--)
    {
        cin>>s;
        insert_(root,s);
    }

    cin>>q;
    while(q--)
    {
        cin>>s;

        if(search_(root,s))
        {
            cout<<"present"<<endl;
        }
        else
        {
            cout<<"not present"<<endl;
        }
    }

    return 0;
}
