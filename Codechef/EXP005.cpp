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
#define mx5 100005
#define mx6 1000006
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;
int main() {

    int t;
    scanf("%d", &t);
    string s,s1;
    int ex, ex1;

    while(t--) {

        cin>>s;
        cin>>s1;
		ex=0;
		ex1=0;

        bool open=false;
        bool sign=true;

        for(int i=0; i<s.length(); i++) {

            if(s[i] == '(') {
                open = true;
                if(i!=0) {
                    if(s[i-1] == '-')
						sign = false;
					else
                        sign = true;
				} else {
						sign = true;
				}

			} else if(s[i] == ')') {
                open = false;
                sign = true;

			} else if( (int)(s[i]) >= 97 && (int)(s[i]) <= 122 ) {

                if(open == true) {
                    if(sign == false){
                        if(s[i-1] == '-'){
                            ex += (int)(s[i]);
                        } else {
                            ex -= (int)(s[i]);
                        }
                    } else {
                        if(s[i-1] == '-'){
                            ex -= (int)(s[i]);
                        } else {
							ex += (int)(s[i]);
                        }
                    }
                } else {
                    if(i==0){
                        ex += (int)(s[i]);
                    } else {
                        if(s[i-1] == '-') {
                            ex -= (int)(s[i]);
                        } else {
                        	ex += (int)(s[i]);
                        }
                    }
                }
			}
        }

        open=false;
        sign=false;

        for(int i=0; i<s1.length(); i++) {

            if(s1[i] == '(') {
                open = true;
                if(i!=0) {
                    if(s1[i-1] == '-')
						sign = false;
					else
                        sign = true;
				} else {
						sign = true;
				}

			} else if(s1[i] == ')') {
                open = false;
                sign = true;

			} else if( (int)(s1[i]) >= 97 && (int)(s1[i]) <= 122 ) {

                if(open == true) {
                    if(sign == false){
                        if(s1[i-1] == '-'){
                            ex1 += (int)(s1[i]);
                        } else {
                            ex1 -= (int)(s1[i]);
                        }
                    } else {
                        if(s1[i-1] == '-'){
                            ex1 -= (int)(s1[i]);
                        } else {
							ex1 += (int)(s1[i]);
                        }
                    }
                } else {
                    if(i==0){
							ex1 += (int)(s1[i]);
                    } else {
                        if(s1[i-1] == '-') {
                            ex1 -= (int)(s1[i]);
                        } else {
                        	ex1 += (int)(s1[i]);
                        }
                    }
                }
			}
        }

        if(ex == ex1) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
	}

	return 0;
}
