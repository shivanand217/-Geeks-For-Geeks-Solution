#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)

#define mx5 100005
#define mx6 1000006
#define mod 1000000007

#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)

using namespace std;

typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
struct trie {
    bool isEndOfWord;
    struct trie *children[60];
    trie() {
        isEndOfWord = false;
        for(int i = 0; i < 60; i++){
            children[i] = NULL;
        }
    }
};

void insert_(struct trie *root, string key) {
    struct trie *pCrawl = root;
    int index;
    for (int i = 0; i < key.length(); i++) {
        if(key[i] <= 'z' && key[i] >= 'a'){
            index = key[i]-'a';
        }
        if(key[i] <= 'Z' && key[i] >= 'A'){
            index = key[i]-'A';
        }
        if ( pCrawl->children[index] == NULL )
            pCrawl->children[index] = new (struct trie);
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord=true;
}

void search2( struct trie *root, string s1 ) {
    char ch='a'; // start with a
    string s2 = s1;
    if(root->isEndOfWord==true) {
        cout<<s1<<endl;
    }
    struct trie *crawl = root;
    for(int i = 0; i < 26; i++) {
        if(crawl->children[i] != NULL) {
            ch = ch + i;
            s2 = s2 + ch;
            ch = 'a';
            search2(crawl->children[i], s2);
            s2 = s1;
        }
    }
}

void search_(struct trie *root, string s) {
    struct trie *pcrawl = root;
    string k = "";
    int index;
    for(int i=0; i < s.length(); i++) {
        index = s[i]-'a';
        if(pcrawl->children[index] == NULL) {
            cout<<"No suggestions"<<endl;
            insert_(root,s);
            return;
        }
        pcrawl=pcrawl->children[index];
    }
    search2(pcrawl, s);
}

int main() {
    fast;
    int t,q;
    cin>>t;
    string s;
    struct trie *root = new struct trie;
    while( t-- ) {
        cin>>s;
        insert_(root, s);
    }
    cin>>q;
    while(q--) {
        cin>>s;
        search_(root, s);
    }
    return 0;
}
