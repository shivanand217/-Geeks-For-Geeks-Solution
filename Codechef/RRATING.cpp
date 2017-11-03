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

priority_queue<int> max_heap, temp;
priority_queue<int, vector<int>, greater<int> > min_heap;

int main() {

    int n , current_total=0, tmp, cnt, type, x;
    si(n);
    for(int i=0; i<n; i++) {
        si(type);
        if(type == 1){

            si(x);
            current_total++;

            if(current_total < 3){
                temp.push(x);

            } else if(current_total == 3){

            	temp.push(x);
                cnt = (current_total/3);

                while(cnt){
                    int kl = temp.top();
                    temp.pop();
                    min_heap.push(kl);
                    cnt--;
                }

                while(!temp.empty()){
                    int kl = temp.top();
                    temp.pop();
                    max_heap.push(kl);
                }

            } else {

                cnt = (current_total/3);
                bool ok = false;

                if(min_heap.size() < cnt){

                    if( x >= min_heap.top() && x >= max_heap.top() ) {

                        if(min_heap.top() >= max_heap.top()){
                            min_heap.push(x);
                        } else {

                            int k = min_heap.top();
                            int p = max_heap.top();
                            min_heap.pop();
                            max_heap.pop();
                            min_heap.push(p);
                            min_heap.push(x);
                            max_heap.push(k);

                        }
                        ok = true;
                    }

                    if( ok == false && min_heap.top() >= x && min_heap.top() >= max_heap.top() ) {
                        if(max_heap.top() > x){
                            int k = max_heap.top();
                            max_heap.pop();
                            max_heap.push(x);
                            min_heap.push(k);

                        } else {
                            min_heap.push(x);
                        }

                        ok=true;
                    }

                    if( ok == false && max_heap.top() >= x && max_heap.top() >= min_heap.top() ){

                        if(min_heap.top() >= x){
                            int k = max_heap.top();
                            max_heap.pop();
                            max_heap.push(x);
                            min_heap.push(k);
                        } else {
                            int k = min_heap.top();
                            int p = max_heap.top();
                            min_heap.pop();
                            max_heap.pop();
                            min_heap.push(p);
                            min_heap.push(x);
                            max_heap.push(k);
                        }
                        ok = true;
                    }

                } else {
                    if(min_heap.top() < x){
                        int kl = min_heap.top();
                        min_heap.pop();
                        max_heap.push(kl);
                        min_heap.push(x);
                    } else {
                        max_heap.push(x);
                    }
                }
            }
        } else {
            if(floor(current_total/3) == 0){
                printf("No reviews yet\n");
            } else {
                printf("%d\n", min_heap.top());
            }
        }
    }
    return 0;
}
