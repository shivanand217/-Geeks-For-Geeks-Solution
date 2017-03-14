// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

// TIME COMPLEXITY : O(n*max_char) // max char is the max_length of word in the given list
// SPACE COMPLEXITY : O(n*key*26)

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define ret return 0;
#define ll long long
using namespace std;

struct trie
{
  struct trie *child[26];
  int count_;
  bool is_leaf;
};

struct trie *new_node()
{
 struct trie *tmp = NULL; // important used while indicating null node in traversing

 tmp=(struct trie *)malloc(sizeof(struct trie));

 for(int i=0; i<26; i++)
 {
    tmp->child[i]=NULL;
 }
 tmp->is_leaf=false;
 tmp->count_=1; // indicating node is visited only once

 return tmp;
}

struct trie *insert_(struct trie *root, string s)
{
    struct trie *pcrawl = root;

    int index;
    for(int i=0; i<s.length(); i++)
    {
        index = (int)s[i]-(int)'a';

        if(p->child[index] ==NULL)
        {
            p->child[index] = new_node();
        }
        p->child[index]->count_+=1;
        p=p->child[index];
    }

    // finally mark the leaf node
    p ->is_leaf = true;
}

bool

int main()
{

}
