#include<stdio.h>
#include<string.h>

int main()
{
    int t, cnt;
    scanf("%d", &t);

	char ch[1002];
	int n,i;

    while(t--)
	{
		scanf("%d", &n);
		cnt=0;

		scanf("%s", ch);

        for(i=0; i<strlen(ch); i++)
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

