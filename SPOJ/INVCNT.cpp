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
#define mx4 5004
#define rep(i,n) for(int i=0; i<n; i++)
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

ll merge_(ll arr[], ll tmp[], int left, int mid, int right) {

    int i, j, k;
    ll inv_cnt=0;
    i=left;  j=mid;  k=left;

    while(i < mid && j <= right) {
        if(arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
            inv_cnt += (mid - i);
        }
    }

    while(i < mid) {
        tmp[k++] = arr[i++];
    }

    while(j <= right) {
        tmp[k++] = arr[j++];
    }

    for(i=left; i<=right; i++){
        arr[i] = tmp[i];
    }

    return inv_cnt;
}

ll merge_sort(ll arr[], ll tmp[], int left, int right) {
	ll inv_cnt=0;
	int mid;
	if(right > left) {

		mid = ( (left+right)>>1 );
        inv_cnt = merge_sort(arr, tmp, left, mid);
        inv_cnt += merge_sort(arr, tmp, mid+1, right);
        // merge
        inv_cnt += merge_(arr, tmp, left, mid+1, right);
	}

	return inv_cnt;
}

ll mergeSort(int n, ll arr[], ll tmp[]) {
    return merge_sort(arr, tmp, 0, n-1);
}

int main() {
    int t, n;
    si(t);

    while(t--) {
        getchar();
        si(n);

        long long arr[n];
        for(int i=0; i<n; i++){
            slli(arr[i]);
        }

		long long tmp[n];
		long long ans = mergeSort( n, arr, tmp );

		printf("%lld\n", ans);
    }

    return 0;
}
