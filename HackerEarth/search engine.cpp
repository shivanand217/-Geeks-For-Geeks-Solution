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

using namespace std;

struct node {
    struct node* child[26];
    bool isend;
    int pcount;
} *root;

struct node* getnode() {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    memset(temp->child,NULL,sizeof(temp->child));
    temp->isend=false;
    temp->pcount=-1;
    return temp;
}

void insert(string s,int w) {
    struct node* current = root;
    for(int i=0; i < s.length(); i++) {
        int letter = (int)s[i]-(int)'a';
        if(current->child[letter]==NULL) {
            current->child[letter] = getnode();
        }
        if(current->child[letter]->pcount<w)
            current->child[letter]->pcount=w;
        current=current->child[letter];
    }
    current->isend=true;
}

int count_words(string s) {
    struct node* current = root;
    for(int i=0;i<s.length();i++) {
        int letter = (int)s[i]-(int)'a';
        if( current->child[letter] == NULL)
            return -1;
        else
            current = current->child[letter];
    }
    return current->pcount;
}

int main() {
    fast;
    root = (struct node*)malloc(sizeof(struct node));
    memset(root->child,NULL,sizeof(root->child));
    root->isend = false;
    root->pcount=-1;

    int n,q,w;
    string s;
    cin>>n>>q;

    for(int i=0;i<n;i++) {
        cin>>s;
        cin>>w;
        insert(s,w);
    }

    while(q--) {
        cin>>s;
        int ans = count_words(s);
        cout<<ans<<endl;
    }

    return 0;
}
