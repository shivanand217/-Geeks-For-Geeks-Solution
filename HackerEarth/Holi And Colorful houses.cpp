#include<bits/stdc++.h>
#define maxx 1010
using namespace std;

string str;
int m,n;
int N,Q,t,len;

int main() {
    scanf("%d",&t);
    int cost1, cost2;

    while(t--) {
        cin>>N>>Q;
        cin>>str;
        len = str.length();

        for(int i=0; i < Q; i++) {
            cost1 = 0; cost2 = 0;
            cin>>m>>n;
            m -= 1;
            n -= 1;

            int st;
            /** traverse anti-clock-wise **/
            /** here we will get the cost1 due to traversing in anti-clock-wise **/
            st = m;
            while(st != n) {
                if(st == n) {
                    break;
                }
                if(st == 0) {
                    st = len-1;
                    if(str[st] != str[0]){
                        cost1++;
                    }
                } else {
                    st--;
                    if(str[st] != str[st+1]) {
                        cost1++;
                    }
                }
            }

            /** traverse clock-wise **/
            /** here we will get cost2 by traversing in clock-wise direction **/
            st = m;
            while(st != n) {
                if(st == n)
                    break;
                if(st == len-1) {
                    st=0;
                    if(str[0] != str[len-1]){
                        cost2++;
                    }
                } else {
                    st++;
                    if(str[st-1] != str[st]){
                        cost2++;
                    }
                }
            }

            cout<<min(cost1,cost2)<<endl;
        }
    }

    return 0;
}
