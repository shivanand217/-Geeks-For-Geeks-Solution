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
#define mx5 100005
#define mx6 1000006
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;

int main() {
    int n;
    si(n);

    string s;
    cin>>s;

    unordered_map<char, int> po;
    for(int i=0; i<s.length(); i++) {
        po[s[i]]++;
    }

    string req = "codechef";
    unordered_map<char, int> un;

    for(int i=0; i<req.length(); i++){
        un[req[i]]++;
    }

    int tmp;
    int tot = INT_MAX;

    for(int i=0; i < req.length(); i++){
        tmp = (po[req[i]])/(un[req[i]]);
        if(tot > tmp){
            tot = tmp;
        }
	}

    cout<<tot<<endl;
    return 0;
}
