#include<bits/stdc++.h>
using namespace std;

long long BIT[100005];

int mxx = 100001;

long long sum(int index) {
    long long s = 0LL;

    while(index > 0) {
         s += BIT[index];
         index = index - (index & (-index));
    }
    return s;
}

void update(int index, int value) {
	while(index <= mxx) {
		BIT[index] += value;
		index = index + (index & (-index));
	}
}

int main() {
	int t;
	scanf("%d", &t);

	int n;
	long long tmp,ans;

	while(t--) {
		memset(BIT, 0LL, sizeof(BIT));

		scanf("%d",&n);

		int arr[n + 9], temp[n + 9];

		ans = 0LL;

		for(int i=0; i < n; i++) {
			scanf("%d", &arr[i]);
			temp[i] = arr[i];
		}

		sort( arr, arr + n );

		for(int i = 0; i < n; i++) {
			int pos = lower_bound(arr, arr + n , temp[i]) - arr;
			temp[i] = pos;
		}

		ans = 0;

		for(int i=0; i < n; i++) {
			ans += sum(temp[i]);

			/** we have to send update to bit by increasing index by one but in original array it
                will be at same position temp[i] **/

			update(temp[i] + 1, arr[temp[i]]);
		}

		printf("%lld\n", ans);
	}

	return 0;
}
