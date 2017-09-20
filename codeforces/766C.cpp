#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define mp make_pair
#define ss second
#define mm(a,b) memset(a,b,sizeof(b))
#define pp pair<ll,ll>
#define mp make_pair
using namespace std;

#define LONG_LONG_MAX 1000000000000
#define N 1005
#define M 1000000007
int n;
string s;

ll dp[N];  //splits
ll mn_split[N];
ll cnt[28];

int main()
{

    cin>>n>>s;

    for(int i=0;i<26;i++)cin>>cnt[i];
    for(int i=1;i<N;i++)mn_split[i]=LONG_LONG_MAX;

    dp[0] = 1; //one sort of split
    mn_split[0] = 1; //single substring
    int max_size = 1;
    vector<bool> vst(26,0);

    for(int i=1;i<n;i++)
    {
        int chr = s[i]-'a' , cont = 0;

        for(int k=0;k<26;k++)vst[k]=0;
        vst[chr]=1;

        for(int j=i;j>=0;j--)
        {
            int len = i-j+1;
            bool possible = 1;

            vst[s[j]-'a']=1;

            for(int k=0;k<26;k++)
                if(vst[k]==true)
                    if(len>cnt[k])possible=0;

            if(possible) //this substring is possible
            {
                max_size = max(max_size,len);
                ll pv_valids = (j==0)?1:dp[j-1];
                dp[i] = (dp[i] + pv_valids )%M;

                mn_split[i] = min(mn_split[i], ((j==0)?0:mn_split[j-1])+1); //if split at j then total substrings
            }
            else
                break;
        }
    }

    //for(int i=0;i<n;i++)cout<<dp[i]<<" ";

    cout<<dp[n-1]<<endl;
    cout<<max_size<<endl;
    cout<<mn_split[n-1]<<endl;

}
