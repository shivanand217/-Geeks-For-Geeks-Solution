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
#define mx4 5004
#define rep(i,n) for(int i=0; i<n; i++)
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

int t,n,cnt,tmp,nb1;

int main() {

    si(t);

    while(t--) {
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int> > min_heap;

        while(true) {

        si(n);
        if(n == 0)
			break;

        else if(n == -1) {

            printf("%d\n", max_heap.top());
            max_heap.pop();

            if(max_heap.size() < min_heap.size()) {
                tmp = min_heap.top();
                min_heap.pop();
                max_heap.push(tmp);
            }

        } else {
            if(max_heap.size() == 0 && min_heap.size() == 0)
				max_heap.push(n);
            else {
				nb1 = max_heap.top();
                if(n >= nb1)
					min_heap.push(n);
                else
                    max_heap.push(n);

                if(max_heap.size() < min_heap.size()){
                    tmp = min_heap.top();
                    min_heap.pop();
                    max_heap.push(tmp);
				} else if (max_heap.size() > min_heap.size() + 1){
                    tmp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(tmp);
				}
            }
        }
	}
}

   return 0;
}
