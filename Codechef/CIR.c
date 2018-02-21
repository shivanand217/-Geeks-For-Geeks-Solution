#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int x1, y1, r1; scanf("%d%d%d", &x1, &y1, &r1);
		int x2, y2, r2; scanf("%d%d%d", &x2, &y2, &r2);
		long long centreDistance = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
		if(centreDistance==0 && r1==r2)
			printf("C2~C1\n");
		else if(r1 > (centreDistance+r2))
			printf("C1CC2\n");
		else if(r2 > (centreDistance+r1))
			printf("C2CC1\n");
		else
			printf("NOT SATISFIED\n");
	}
}
