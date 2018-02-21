#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max 1000016

int prime[max];
int prefix[max];

void seive() {
    memset(prime,0,sizeof(prime));
    prime[1] = prime[0] = 1;
    long long i,j;
    for(i=2; i*i < max-10; i++) {
        if(prime[i] == 0) {
            for(j=2*i; j < max-10; j += i){
                prime[j] = 1;
            }
        }
    }
}

int main() {
    seive();
    int t,L,R;
    scanf("%d", &t);
    memset(prefix,0,sizeof(prefix));
    prefix[0] = prefix[1] = 0;
    int i;
    for( i = 2; i < max; i++ ) {
        if(prime[i] == 0) {
            prefix[i] = prefix[i-1] + 1;
        } else {
            prefix[i] = prefix[i-1];
        }
    }
    double ans;
    int num;
    int pr;
    while(t--) {
        scanf("%d %d", &L, &R);
        num = R - L + 1;
        pr = (prefix[R] - prefix[L-1]);
        ans = (double)(pr*1.0)/(num*1.0);
        printf("%.6f\n",ans);
    }

    return 0;
}
