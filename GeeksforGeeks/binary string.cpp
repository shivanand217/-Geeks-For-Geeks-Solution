#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, cnt;
    scanf("%d", &t);

	char ch[1002];
	int n;

    while(t--)
	{
		scanf("%d", &n);
		cnt=0;

		scanf("%s", ch);

        for(int i=0; i<strlen(ch); i++)
		{
            if(ch[i] == '1')
			{
                cnt++;
			}
		}

		printf("%d\n", (cnt*(cnt-1)/2));
	}
    return 0;
}
