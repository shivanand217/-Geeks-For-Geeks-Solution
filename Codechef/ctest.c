#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    double n,m;
    double pi = 3.141592;
    char buffer[256];
    fgets(buffer,256,stdin);
    n = atof(buffer);
    m = sin(n * pi/180);
    printf("sin of %f is %f\n",n,m);

    /** atoi **/
    long long i;
    fgets(buffer, 256, stdin);
    i = (long long)atoi(buffer);
    printf("The value entered is %lld. Its double is %lld\n", i, i*2);

    /** strtof **/
    char szOrbits[] = "600.00 700.00 800.00 900.00 200.00";
    char *pEnd;
    float f1,f2,f3;

    f1 = strtof(szOrbits, &pEnd);
    f2 = strtof(pEnd, &pEnd);
    printf("f1 is %f, f2 is %f",f1, f2);


    //while(pEnd != NULL) {
      //  printf("%f\n", f1);
      //  f1 = strtof(pEnd, &pEnd);
    //}
    //printf("ans is %.2f\n",f1/f2);

    return 0;
}
