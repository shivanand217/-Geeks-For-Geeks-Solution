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

int Solve_dp(string s) {
    int ans=0;
    int table[s.length()+2][s.length()+2];

    memset(table, 0, sizeof(table));

    /** dp is used as about number of
        possible gaps

        Like for  string "abcde"
        gap length 1 : [a-b],[b-c],[c-d],[d-e];
        gap length 2 : [a-c],[b-d],[c-e]
        and so on... */

    /** recursion can be solved as
    minimum insertion required in string [l....h]
    is if s[l]=s[h] then we go for [l+1....h-1]
    otherwise we have to check for minimum between [l+1...h]
    [l...h-1] and add one to this **/

    int gap = 1;
    int l=0 , h=0;

    for(gap = 1; gap < s.length(); gap++) {
        for(l = 0, h=gap; h < s.length(); ++l, ++h) {
            if(s[l] == s[h]) {
                table[l][h] = table[l+1][h-1];
            } else {
                table[l][h] = min(table[l+1][h],table[l][h-1]) + 1;
            }
        }
    }

    ans = table[0][s.length()-1];

    return ans;
}

int main() {
    fast;
    int t;
    cin>>t;
    string s;
    int ans;

    while(t--) {
        cin>>s;
        ans = Solve_dp(s);
        cout<<ans<<endl;
    }

    return 0;
}

/** below is the recursion

int recursive_solution(string s,int l,int r) {
    // left index exceeds right index
    if(l > r)
        return INT_MAX;
    // indexes are equal
    if(l == r) {
        // no insertion required it is already a palindrome
        return 0;
    }
    // adjacent index
    if(l+1 == r) {
        if(s[l] == s[r])
            return 0;
        else {
            return 1;
        }
    }
    // otherwise indexes are not equal or adjacent
    return min(recursive_solution(s,l+1,r),recursive_solution(s,l,r-1))+1;
}

**/
