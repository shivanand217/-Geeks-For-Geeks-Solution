#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

inline void furr_int(int &num) {
    bool neg=false;
    char ch;
    ch=gc();
    num=0;
    if(ch=='-'){
        neg=true;
        ch=gc();
    }
    for(; (ch>='0' && ch<='9'); ch=gc()){
        num = num*10 + (ch - '0');
    }
    if(neg)
        num *= (-1);
}

inline void writeInt(int n) {
    int N=n,rev,coun=0;
    rev=N;
    if(N==0) {pc('0'); pc('\n');return;}
    while((rev%10) == 0){
        coun++;
        rev /= 10;
    }
    rev = 0;
    // storing reverse of N in rev
    while(N != 0) {
        rev = (rev<<3) + (rev<<1) + N%10;
        N /= 10;
    }
    while(rev != 0) {
        pc(rev%10 + '0');
        rev /= 10;
    }
    while(coun) {
        pc('0');
        coun--;
    }
}

inline void furr_long(ll &num) {
    bool neg=false;
    char ch;
    ch=gc();
    num=0LL;
    if(ch=='-') {
        neg=true;
        ch=gc();
    }
    for(; (ch>='0' && ch<='9'); ch=gc()){
        num = num*10 + (ch - '0');
    }
    if(neg)
        num *= (ll)(-1);
}

inline void writelong(ll n) {
    ll N=n,rev,coun=0LL;
    rev=N;
    if(N==0) {pc('0'); pc('\n');return;}
    while((rev%10) == 0) {
        coun++;
        rev /= 10;
    }
    rev = 0;
    while(N != 0) {
        rev = (rev<<3) + (rev<<1) + N%10;
        N /= 10;
    }
    while(rev != 0) {
        pc(rev%10 + '0');
        rev /= 10;
    }
    while(coun) {
        pc('0');
        coun--;
    }
}

vector<int> lps_array;
string pattern,text;

void compute_lps() {
    int len=0;
    int i=0;
    lps_array[len]=0;
    i = 1;
    while(i < pattern.length()) {
        if(pattern[len] == pattern[i]){
            len++;
            lps_array[i]=len;
            i++;
        } else {
            // mismatch
            if(len != 0) {
                len=lps_array[len-1];
            } else {
                lps_array[i]=0;
                i++;
            }
        }
    }
}

void KMP(int &ans) {
    int i=0,j=0;
    compute_lps();
    int pattern_length=pattern.length();
    int text_length=text.length();
    while(i < text_length) {
        if(pattern[j] == text[i]) {
            i++;
            j++;
        }
        // if matched totally
        if(j == pattern_length) {
            ans++;
            j=lps_array[j-1];
        } else if(i < text_length && text[i] != pattern[j]) {
            // mismatch
            if(j != 0)
                j=lps_array[j-1];
            else
                i++;
        }
    }
}

int main() {
    fast;
    cin>>pattern>>text;
    int ans=0;
    lps_array.resize(pattern.length());
    KMP(ans);
    cout<<ans<<endl;
    return 0;
}
