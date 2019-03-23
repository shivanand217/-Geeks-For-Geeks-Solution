#include<bits/stdc++.h>
using namespace std;
#define N 1000000

// used by c qsort
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int randomize()
{
    return rand()%100000;
}

/** checking both function time by sorting 1 million integers **/

int main()
{
    int ar[N],d[N];
    srand(time(NULL));

    clock_t begin,end;
    double time_spent;

    for(int i=0; i<N; i++)
    {
        d[i] = ar[i] = randomize();
    }

    begin = clock();
    qsort(ar, N, sizeof(int), compare);
    end = clock();

    time_spent = double(end-begin)/CLOCKS_PER_SEC;
    cout<<"time taken by qsort: "<<time_spent<<endl;

    time_spent = 0.0;

    begin = clock();
    sort(d,d+N);
    end = clock();

    time_spent = double(end-begin)/CLOCKS_PER_SEC;

    cout<<"time taken by c++ stls sort(): "<<time_spent<<endl;

    return 0;
}
