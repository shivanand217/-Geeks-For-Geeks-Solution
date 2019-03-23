#include <stdio.h>
#define MAX 1000005

int main()
{
	int T;
	long long int o1, o2, i ,j;
	scanf ("%d" ,&T);

	while(T--){
		int d[MAX];
		int ones[MAX];
		int count, ans;
		scanf ("%lld %lld", &o1 ,&o2);
		for(i=1;i<=o1*o2;i++){
			scanf ("%d", &d[i]);
		}
		for(i=1;i<=o1*o2;i++){
			ones[i]=ones[i-1] + d[i];
		}
		for(i=1;i<=o2;i++){
			ans=0;
			for(j=i;j+o2-1<=o1*o2;j=j+o2){
				count = ones[j+o2-1] - ones[j-1];
				if(count > (o2)/2)
					ans++;
			}
			if(j <= o1*o2){
				count = ones[o1*o2] - ones[j-1] + ones[(j+o2-1)%(o1*o2)];
				if(count > (o2)/2)
					ans++;
			}
			if(ans > (o1/2))
				break;
		}
		if(ans > (o1/2)){
			printf ("1\n");
		}
		if(i == o2+1)
			printf ("0\n");
	}
	return 0;
}
