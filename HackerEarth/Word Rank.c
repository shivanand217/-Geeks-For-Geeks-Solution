#include<stdio.h>
#include<string.h>
#define ll long long
#define mod 1000000007

ll power(ll base,ll exp) {
    ll res=1LL;
    while(exp>0) {
        if((exp&1)) {
            res = ((ll)res*base)%mod;
        }
        exp/=2;
        base = ((ll)base*base)%mod;
    }
	return res;
}

ll fact[25];
ll factorial(){
    ll i,j,k;
    fact[0]=fact[1]=1;
    for(i=2;i<=20;i++){
		fact[i]=i*fact[i-1];
    }
}

int main() {
	ll n,m,i,j,k,t,x;
	factorial();
    scanf("%lld",&t);

    while(t--) {
		char st[55],an[55];
        scanf("%s",st);
        scanf("%lld",&n); // position to find

        ll cnt[26];
        memset(cnt,0LL,sizeof(cnt));
        for(i=0;i<strlen(st);i++){
			cnt[st[i]-'a']++;
        }

        ll lp = strlen(st);
        m=0;
        for(i=0; i<lp; i++) {
            for(j=0; j<26; j++) {
                k = fact[lp-i-1];
                if(cnt[j] > 0) {
                    for(x=0; x < 26; x++) {
                        if(x==j && cnt[x]>0) {
							k /= fact[cnt[x]-1];
                        } else {
                        	k /= fact[cnt[x]];
                        }
                    }
                    if(n > k){
                        n -= k;
                    } else{
                        an[m++]=(char)(j+'a');
                        cnt[j]--;
                        break;
                    }
                }
            }
        }
        an[m]='\0';
        printf("%s\n",an);
    }

	return 0;
}
