#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)

long long a[14];
long long temp[14];

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<14; i++) {
        temp[i]=0;
    }

    for(int i=0; i < 14; i++) {
        cin>>a[i];
    }

    long long num=0LL,rem;
    int j,tmp;
    long long mx = 0;
    long long sum=0LL;
    int last,first;

    for(int i=0; i<14; i++) {
        if(a[i] == 0)
            continue;

        /** if we are emptying current cell **/
        rem = a[i]/14;
        sum = 0LL;

        if(rem == 0) {
            j = a[i]%14;
            tmp = i+1;

            while(j > 0) {
                if(tmp == 14) {
                    tmp = 0;
                }
                /** only take if even **/
                if((a[tmp]+1)%2 == 0)
                    sum += (a[tmp]+1);
                tmp++;
                j--;
            }

            if(sum > mx) {
                mx = sum;
            }

        } else {
            /** rem must be added to all the cells **/
            for(int p=0; p < 14; p++) {
                temp[p]=rem;
            }

            /** then add left stones to rest of the cells **/
            j = a[i]%14;
            tmp = i+1;
            last = tmp;
            if(last == 14)
                last=0;

            while(j > 0) {
                if(tmp == 14){
                    tmp=0;
                }
                if((a[tmp]+1+temp[tmp])%2 == 0)
                    sum += a[tmp]+1+temp[tmp];
                tmp++;
                j--;
            }

            first = tmp;
            if(first == 14)
                first=0;

            int m = first;
            while(m != last) {
                if(m == 14)
                    m=0;
                if(m==last)
                    break;
                if((a[m]+temp[m])%2 == 0) {
                    sum += (a[m]+temp[m]);
                }
                m++;
            }

            if(sum > mx) {
                mx = sum;
            }
        }
    }

    cout<<mx<<endl;

    return 0;
}
