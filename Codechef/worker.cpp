/** 10 April 2018 **/

#include<bits/stdc++.h>
using namespace std;

const int mx = 10005;
int cost[mx];
int n , type;

int _min(int a, int b) {
     if(a < b) {
     	return a;
     } else {
     	return b;
     }
}

int main() {
	scanf("%d", &n);
	int write_min = INT_MAX, read_min = INT_MAX, both_min = INT_MAX;
	
	for(int i=1; i <= n; i++) {
	    scanf("%d", &cost[i]);
	}
	
	int a=0,b=0,c=0;
	
	for(int i=1; i<=n; i++) {
		scanf("%d", &type);
		if(type == 1) {
			a++;
			write_min = _min(write_min, cost[i]);		
		} 
		if(type == 2) {
			b++;
			read_min = _min(read_min, cost[i]);
		} 
		if(type == 3) {
			c++;
			both_min = _min(both_min, cost[i]);
		}
	}
	
	/** subtask 1 **/
	if(a == 0 && b == 0) {
	    cout<<both_min<<endl;
	    return 0;
	}
	
	/** subtask 2 **/
	if(write_min == INT_MAX || read_min == INT_MAX) {
	    cout<<both_min<<endl;
	    return 0;
	}
	write_min += read_min;
	int ans = min(write_min, both_min);
	cout<<ans<<endl;
	
	return 0;
}