#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back

#define ss second
#define ff first
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

typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

int main() {
    int t;
    cin>>t;
    string s,a;
    while(t--) {
        cin>>s;
        a="";
        for(int i=0;i<s.length();i++) {
            if( s[i]>='a' && s[i]<='z' ) {
                a += s[i];
            }
            if(s[i]>='A'&&s[i]<='Z') {
                s[i]=tolower(s[i]);
                a += s[i];
            }
        }
        //cout<<a<<endl;
        int ans = 0;
        int one,two,thr,fou;
        for(int i=0; i < a.length(); i++) {
            if(a[i] == 'f') {
                one=1,two=0,thr=0,fou=0;
                if(i <= a.length()-4) {
                    //i+1
                    if(a[i+1]=='c')two++;
                    if(a[i+1]=='h')thr++;
                    if(a[i+1]=='e')fou++;
                    //i+2
                    if(a[i+2]=='c')two++;
                    if(a[i+2]=='h')thr++;
                    if(a[i+2]=='e')fou++;
                    //i+3
                    if(a[i+3]=='c')two++;
                    if(a[i+3]=='h')thr++;
                    if(a[i+3]=='e')fou++;
                }
                if(one>0 && two>0 && thr>0 && fou>0){
                    ans++;
                }
            }
            if(a[i] == 'c') {
                one=1,two=0,thr=0,fou=0;
                if(i <= a.length()-4 ) {
                    //i+1
                    if(a[i+1]=='f')two++;
                    if(a[i+1]=='h')thr++;
                    if(a[i+1]=='e')fou++;
                    //i+2
                    if(a[i+2]=='f')two++;
                    if(a[i+2]=='h')thr++;
                    if(a[i+2]=='e')fou++;
                    //i+3
                    if(a[i+3]=='f')two++;
                    if(a[i+3]=='h')thr++;
                    if(a[i+3]=='e')fou++;
                }
                if(one>0 && two>0 && thr>0 && fou>0){
                    ans++;
                }
            }
            if(a[i] == 'h') {
                one=1,two=0,thr=0,fou=0;
                if(i <= a.length()-4 ) {
                    //i+1
                    if(a[i+1]=='c')two++;
                    if(a[i+1]=='f')thr++;
                    if(a[i+1]=='e')fou++;
                    //i+2
                    if(a[i+2]=='c')two++;
                    if(a[i+2]=='f')thr++;
                    if(a[i+2]=='e')fou++;
                    //i+3
                    if(a[i+3]=='c')two++;
                    if(a[i+3]=='f')thr++;
                    if(a[i+3]=='e')fou++;
                }
                if(one>0 && two>0 && thr>0 && fou>0){
                    ans++;
                }
            }
            if(a[i] == 'e') {
                one=1,two=0,thr=0,fou=0;
                if( i <= a.length()-4 ) {
                    //i+1
                    if(a[i+1]=='c')two++;
                    if(a[i+1]=='h')thr++;
                    if(a[i+1]=='f')fou++;
                    //i+2
                    if(a[i+2]=='c')two++;
                    if(a[i+2]=='h')thr++;
                    if(a[i+2]=='f')fou++;
                    //i+3
                    if(a[i+3]=='c')two++;
                    if(a[i+3]=='h')thr++;
                    if(a[i+3]=='f')fou++;
                }
                if(one>0 && two>0 && thr>0 && fou>0){
                    ans++;
                }
            }
        }
        if( ans > 0 ) {
            cout<<"lovely "<<ans<<endl;
        } else {
            cout<<"normal"<<endl;
        }
    }

    return 0;
}
