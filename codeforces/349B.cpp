#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,m,k,n,x,y;
    scanf("%d", &t);
    string s;

    int a[2]={0};

    while(t--) {

        cin>>s;
        scanf("%d %d", &x, &y);
        a[0]=a[1]=0;

        for(int i=0; i<s.length() ; i++){
            if(s[i]=='a')
                a[0]++;
            else
                a[1]++;
        }

        if(a[0] == a[1]){

            for(int i=0; i<s.length() ;i++){
                if((i&1)){
                    putchar('a');
                }
				else
					putchar('b');
            }	putchar('\n');

        } else if(a[0] > a[1]) {

			while(a[0]>a[1] && a[0]>0) {

			int limit = min(x, (a[0]-a[1]));
			for(int i=0; i < limit; i++){
                putchar('a');
            }
				a[0] -= limit;

                if(a[1] > 0)
					{putchar('b'); --a[1]; }
                else if(a[0] > 0)putchar('*');
			}

				putchar('\n');

        } else {
			while(a[1]>a[0] && a[1]>0){

			int limit = min(y, (a[1]-a[0]));
			for(int i=0; i<limit; i++){
                putchar('b');
            }
				a[1] -= limit;

                if(a[0] > 0)
					{putchar('a'); --a[0]; }
                else if(a[1] > 0)putchar('*');;
			}

			putchar('\n');
        }

        }

    return 0;
}
