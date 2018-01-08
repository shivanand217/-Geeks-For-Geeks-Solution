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


int main() {
	int t;
	scanf("%d",&t);

	long long b;
	int a,ad,r;

	int input[][6] = { {0}, {1}, {2,4,8,6,2},{3,9,7,1},{4,6},{5},{6},{7,9,3,1},{8,4,2,6},{9,1}};

	while(t--) {
		scanf("%d%lld",&a,&b);

		ad = a%10;

		if (a==0)
			r = 0;
		else if (b==0)
			r=1;
		else if (ad==0 || ad==1 || ad==5 || ad==6)
			r=input[ad][0];
		else if(ad==2 || ad==3 || ad==7 || ad==8)
			r = input[ad][(b-1)%4];
		else if(ad==4 || ad==9)
			r = input[ad][(b&1)?0:1];

		printf("%d\n",r);
	}

	return 0;
}
