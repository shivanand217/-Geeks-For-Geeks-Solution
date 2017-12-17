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

int main() {
    fast;
    string s;
    while( getline(cin,s) ) {
        int fir=0 , sec=0;
        bool winner = false;
        int cnt;
        for(int i=0; i < s.length(); i++) {
                if(s[i]=='1' && !(i&1)) {
                    fir++;
                }
                if(s[i]=='1' && (i&1)) {
                    sec++;
                }
                if((i&1) && i > 10) {
                if( fir > sec ) {
                    winner = false;
                    cnt = i+1;
                    break;
                } else if( fir < sec ) {
                        winner = true;
                        cnt = i+1;
                        break;
                    }
                }
                if(i<9) {
                    if( (i&1) ) {
                        int left = (9 - i)/2;
                        if(sec+left < fir) {
                            winner=false;
                            cnt=i+1;
                            break;
                        }
                        if(fir+left < sec) {
                            winner=true;
                            cnt=i+1;
                            break;
                        }
                    } else {
                        int lefteven = (9 - i)/2;
                        int leftodd = lefteven+1;
                        if(fir+lefteven < sec){
                            winner=true;
                            cnt=i+1;
                            break;
                        }
                        if(sec+leftodd < fir){
                            winner=false;
                            cnt=i+1;
                            break;
                        }
                    }
                }
                if(i==9) {
                    if(fir > sec) {
                        cnt=i+1;
                        winner=false;
                        break;
                    } else if(fir < sec) {
                        cnt=i+1;
                        winner=true;
                        break;
                    }
                }
        }
        if(fir == sec) {
            cout<<"TIE"<<endl;
        }
        else {
            if(winner == false) {
                cout<<"TEAM-A "<<cnt<<endl;
            } else {
                cout<<"TEAM-B "<<cnt<<endl;
            }
        }
    }

    return 0;
}
