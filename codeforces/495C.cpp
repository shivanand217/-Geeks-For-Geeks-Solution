#include<bits/stdc++.h>
#define ll long long
#define SZ(x) ((ll)x.size())
using namespace std;

ll h, n;

int main()
{
    string s;
    cin >> s;

    int open=0, close=0, unknown=0;
    bool poss=1;

    for(int i=0; i<SZ(s); i++){
        if(s[i]=='('){open++;}
        else if(s[i]==')'){close++;}
        else{unknown++;}
        if(open<close+unknown){
            poss=0;
            break;
        }
    }

    if(!poss){
        cout << "-1" << endl;
        return 0;
    }

    int required=open-close;
    int f[unknown+1], g[unknown+1], ans[unknown];
    int count=0, i=0;

    while(i!=SZ(s)){
        if(s[i]=='('){f[count]++;}
        if(s[i]==')'){g[count]++;}
        if(s[i]=='#'){count++;}
        i++;
    }

    i=0;
    while(i!=unknown-1){
        ans[i]=1;
        i++;
    }

    ans[unknown-1]=required-(unknown-1);
    count=0; poss=1;
    open=close=0;

    for(int i=0; i<SZ(s); i++){
        if(s[i]=='('){open++;}
        if(s[i]==')'){close++;}
        if(s[i]=='#'){close+=ans[count]; count++;}
        if(open<close){
            poss=0;
            break;
        }
    }

    if(open!=close){poss=0;}

    if(!poss){
        cout << "-1" << endl;
        return 0;
    }

    for(int i=0; i<unknown; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
