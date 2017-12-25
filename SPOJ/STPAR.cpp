#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
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

int main() {
    int n;
    cin>>n;

    while(n != 0) {
        int v;
        queue<int> Q;
        stack<int> S;
        for(int i=0;i<n;i++){
            cin>>v;
            Q.push(v);
        }

        int c=1;
        while(!Q.empty()||!S.empty()){
            if(!Q.empty()&&Q.front()==c) {
            Q.pop();
                c++;
            }else{
                if(!S.empty()&&S.top()==c){

                    S.pop();
                    c++;
                }else{
                    if(!Q.empty()){
                        int s=Q.front();
                        S.push(s);
                        Q.pop();
                    }else{
                        break;
                    }
                }
            }
        }
        if(c==n+1){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
        cin>>n;
    }

    return 0;
}
