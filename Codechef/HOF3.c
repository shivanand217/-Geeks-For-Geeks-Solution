#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int t;
    scanf("%d",&t);

    int x1,y1,x2,y2,r1,r2;
    double dist,R;

    while(t--) {

        scanf("%d %d %d",&x1, &y1, &r1);
        scanf("%d %d %d",&x2, &y2, &r2);

        dist=(double)sqrt( 1.0*(x1-x2)*(x1-x2)*1.0 + 1.0*(y1-y2)*(y1-y2)*1.0 );
        R = (double)( r1*1.0 + 1.0*r2 );

        if(R < dist) {
            printf("not overlapping\n");
        } else if(R == dist) {
            printf("tangential\n");
        } else {
            printf("overlapping\n");
        }

    }

    return 0;
}
