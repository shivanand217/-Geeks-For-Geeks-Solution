#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define pc putchar('\n')
#define ps putchar(' ')
using namespace std;

int main()
{
    int a, b, f, k;
    si(a); si(b); si(f); si(k);

    int now=0;
    int total=0;

    bool ans = true;
    int dir = 1, val;
    int req=0;
    int max_limit = b;

	if(f > b)
	{
		ans = false;
	}

    b -= (f);
	now = f;

    while(total < k && ans)
	{
        if(dir == 1)
		{
			val = a - f;

            if(total == k-1)
			{
                if(b < val)
				{
                    req++;
                    b = max_limit;
                    if(b < val)
					{
						ans = false;
					}
				}
				break;
			}

            if(b < 2*val)
			{
                req++;
                b = max_limit;

                if(b < 2*val)
				{
                    ans = false; break;
				}
				else{
                    total++;
                    b -= 2*val;
				}
			}
			else{
                total++;
                b -= 2*val;
			}

			dir = 1- dir;
		}
		else{
            val = f;

            if(total == k-1)
			{
                if(b < val)
				{
                    req++;
                    b = max_limit;
                    if(b < val)
					{
                        ans = false;
					}
				}
				break;
			}

            if(b < 2*f)
			{
                req++;
				b = max_limit;

                if(b < 2*val)
				{
                    ans = false; break;
				}
				else{
                    total++;
                    b -= 2*val;
				}
			}
			else{
                total++;
                b -= 2*val;
			}
			dir = 1 - dir;
		}
	}

    if(ans == false)
	{
        pi(-1);
        pc;
	}
	else
	{
        pi(req);
        pc;
	}

    return 0;
}
