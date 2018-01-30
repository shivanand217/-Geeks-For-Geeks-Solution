#include<bits/stdc++.h>
using namespace std;

bool fib[10005];
char ans[1005];
void pre() {
    int a=1,b=1;
    fib[a] = true;
    fib[b] = true;
    int c,tmp;
    while(c <= 1010) {
        c = a+b;
        fib[c] = true;
        tmp=b;
        a=b;
        b=c;
    }
}

int main() {
    memset(fib,false,sizeof(fib));
    pre();
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        if(fib[i]==true) {
            ans[i-1] = 'O';
        } else {
            ans[i-1] = 'o';
        }
    }

    printf("%s\n",ans);

    return 0;
}
