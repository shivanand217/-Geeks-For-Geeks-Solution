#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define pc putchar('\n')
#define ps putchar(' ')
using namespace std;
vector<string> init(){
    vector<string> v;
    v.push_back("A");
    v.push_back("Ab");
    v.push_back("Abc");
    v.push_back("Abcd");
    v.push_back("Abcde");
    v.push_back("Abcdef");
    v.push_back("Abcdefg");
    v.push_back("Abcdefgh");
    v.push_back("Abcdefghi");
    v.push_back("Abcdefghij");
    v.push_back("B");
    v.push_back("Ba");
    v.push_back("Bac");
    v.push_back("Bacd");
    v.push_back("Bacde");
    v.push_back("Bacdef");
    v.push_back("Bacdefg");
    v.push_back("Bacdefgh");
    v.push_back("Bacdefghi");
    v.push_back("Bacdefghij");
    v.push_back("C");
    v.push_back("Ca");
    v.push_back("Cab");
    v.push_back("Cabd");
    v.push_back("Cabde");
    v.push_back("Cabdef");
    v.push_back("Cabdefg");
    v.push_back("Cabdefgh");
    v.push_back("Cabdefghi");
    v.push_back("Cabdefghij");
    v.push_back("D");
    v.push_back("Da");
    v.push_back("Dab");
    v.push_back("Dabc");
    v.push_back("Dabce");
    v.push_back("Dabcef");
    v.push_back("Dabcefg");
    v.push_back("Dabcefgh");
    v.push_back("Dabcefghi");
    v.push_back("Dabcefghij");
	v.push_back("E");
    v.push_back("Ea");
    v.push_back("Eab");
    v.push_back("Eabc");
    v.push_back("Eabcd");
    v.push_back("Eabcdf");
    v.push_back("Eabcdfg");
    v.push_back("Eabcdfgh");
    v.push_back("Eabcdfghi");
    v.push_back("Eabcdfghij");
    return v;
}
int main()
{
    int n , k;
    si(n); si(k);

    vector<string> v = init();
    string s;
    vector<string> ans;
    unordered_map<string,int> un;

    int index_prev = -1;

    for(int i=1; i<=(n-k+1); i++)
	{
        cin>>s;

        if(i == 1)
		{
            if(s == "YES")
			{
                for(int j=0; j<k; j++)
				{
                    ans.push_back(v[j]);
                    un[v[j]]++;
				}
			}
			else
			{
                ans.push_back("A");
                ans.push_back("A");
                un["A"]++;
                un["A"]++;
                int m=0;

                for(int j=3; j<=k;)
				{
                    if(un[v[m]]==0)
						{ans.push_back(v[m]); un[v[m]]++; j++;}
					m++;
             	}
			}
		}
        else {

		un[ans[index_prev]]--;
        if(s == "YES")
		{
            for(int j=1; j<v.size(); j++)
			{
                if(un[v[j]] == 0)
				{
                    ans.push_back(v[j]);
                    un[v[j]]++;
                    break;
				}
			}
		}
		else
		{
            ans.push_back(ans[index_prev+1]);
				un[ans[index_prev+1]]++;
		}

        }
			index_prev++;
	}

    for(int i=0; i<ans.size(); i++)
	{
        cout<<ans[i]<<" ";
	}cout<<endl;

	return 0;
}
