#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
vector<pair<int,int> > graph[4];
int cnt=0;
int n;
void solve(int source, int& ans) {
    if(n == 0) {
        return;
    }
    if(graph[source][0].second < graph[source][1].second){
		n-=1;
        ans += graph[source][0].second;
        solve(graph[source][0].first, ans);
    } else {
        n-=1;
        ans += graph[source][1].second;
        solve(graph[source][1].first, ans);
    }
    return;
}
int main(){

    int a,b,c;
    cin>>n>>a>>b>>c;
    int ans=0;
	n-=1;
    graph[1].push_back(mp(2,b));
    graph[2].push_back(mp(1,b));
    graph[1].push_back(mp(3,a));
    graph[3].push_back(mp(1,a));
	graph[3].push_back(mp(2,c));
	graph[2].push_back(mp(3,c));
	solve(1, ans);

    cout<<ans<<endl;
    return 0;
}
