#include<stdio.h>
#include<stdlib.h>
int N,X,S,A,B,current_box,i;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d",&N, &X, &S);
        current_box = X;
        for(i=0; i<S; i++) {
            scanf("%d %d", &A, &B);
            if(A==current_box){
                current_box=B;
            }else if(B==current_box){
                current_box=A;
            }
        }
        print("%d\n",current_box);
    }
    return 0;
}
