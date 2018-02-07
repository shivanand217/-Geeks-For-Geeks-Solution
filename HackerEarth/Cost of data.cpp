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
int cnt = 0;

struct node {
    bool leaf;
    struct node *child[26];
    node(){
        leaf=false;
        for(int i=0;i < 26;i++){
            child[i]=NULL;
        }
    }
};

void insert_(struct node *root, string s) {
    struct node *crawl = root;
    int index;
    for(int i=0; i < s.length(); i++) {
        index = s[i] - 'a';
        if(crawl->child[index] != NULL) {
            crawl = crawl->child[index];
        } else {
            cnt++;
            crawl->child[index] = new struct node;
            crawl = crawl->child[index];
        }
    }
    crawl->leaf=true;
}

int main() {
    fast;
    int n;
    cin>>n;
    string s;
    cnt = 1;
    struct node *root = new struct node;
    for(int i=0; i<n; i++) {
        cin>>s;
        insert_(root, s);
    }
    cout<<cnt<<endl;
    return 0;
}

