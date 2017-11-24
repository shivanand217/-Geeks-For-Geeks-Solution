#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define fck std::ios::sync_with_stdio(false);
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

bool prime[mx5];
int a[mx5];
int le[mx5];
int ri[mx5];

void seive() {
    memset(prime,false,sizeof(prime));
    prime[0]=prime[1]=true;
    for(ll i=2;i<mx5;i++){
		if(prime[i]==false){
			for(ll j=i*i;j<mx5;j+=i){
                prime[j]=true;
			}
		}
    }
}

int main() {
	seive();
    int n;
    si(n);

    for(int i=0;i<n;i++){
		si(a[i]);
		le[i]=0;
		ri[i]=0;
    }

    for(int i=0;i<n;i++) {
        if(prime[a[i]]==false) {
            le[i]=i;
            ri[i]=i;
        } else {
        	if(i==0)
				le[i]=-1;
			else
				le[i]=le[i-1];
        }
    }

    for(int i=n-1;i>=0;i--) {
		if(prime[a[i]]==false){
            ri[i]=i;
            le[i]=i;
		} else {
			if(i==n-1){
                ri[i]=-1;
			} else
				ri[i]=ri[i+1];
		}
    }

    for(int i=0;i<n;i++) {
        if(prime[a[i]]==false) {
            printf("%d ",i+1);
        } else {
            if(le[i]==-1&&ri[i]==-1){
				printf("-1 ");
            }
            if(le[i]==-1&&ri[i]!=-1){
				printf("%d ",ri[i]+1);
            }
            if(le[i]!=-1&&ri[i]==-1){
				printf("%d ",le[i]+1);
            }
            if(le[i]!=-1&&ri[i]!=-1){
                if( le[i] == ri[i] ){
                    printf("%d ",le[i]+1);
                } else if( le[i] < ri[i] ){
                    printf("%d ",le[i]+1);
                } else {
                    printf("%d ",ri[i]+1);
                }
            }
        }
    }

	return 0;
}

