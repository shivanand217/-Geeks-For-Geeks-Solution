#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int h[26];
int ans[100005];

bool compare( pair<char,int> p, pair<char,int> q ) {
    return (p.ff < q.ff);
}
int main() {
    int t;
    cin>>t;
    string s;
    vector<pair<char,int> > v;

    while( t-- ) {
        v.clear();
        memset(h, 0, sizeof(h));
        cin>>s;

        int k,j;
        k = (s.length()%2);
        for(int i=0; i < s.length(); i++) {
            h[s[i]-'a']++;
            v.push_back(make_pair(s[i],i+1));
        }
        int one = 0;
        for(int i = 0; i < 26; i++) {
            if(h[i]%2 == 1) {
                one++;
            }
        }

        if(one > k) {
            cout<<"-1"<<endl;
        } else {

            int l = 0;
            sort(v.begin(),v.end(),compare);
            int len = s.length();

            int mid = -1;
            if(one == 1) {
                mid = ((len/2) + 1);
            }

            int i = 0,p,q;
            int lo = 1,hi = len;

            while(i < len) {

                if(i == len-1) {
                    p = v[i].ss;
                    ans[p] = mid;
                    break;
                }
                if( v[i].ff == v[i+1].ff ) {
                    p = v[i].ss;
                    q = v[i+1].ss;
                    ans[p] = lo;
                    ans[q] = hi;
                    lo++; hi--;
                    i += 2;
                    continue;
                }
                if( v[i].ff != v[i+1].ff ) {
                    p = v[i].ss;
                    ans[p] = mid;
                    i++;
                }
            }

            for(int i=1; i<=len; i++) {
                cout<<ans[i]<<" ";
            } cout<<endl;

        }

    }

    return 0;
}
