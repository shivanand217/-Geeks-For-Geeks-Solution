#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

char g[15][15];

int main() {

    fast;
    int x,y;
    int i=1;
    int j=1;
    char k[20];

    for(i=1; i<=9; i++) {
        for(j=1; j<=9; j++) {
            cin>>g[i][j];
        }
    }

    cin>>x>>y;

    int a,b;
    int an;

    if(x%3 == 0){
        a = 3;
    } else {
        a = x%3;
    }

    if(y%3 == 0) {
        b = 3;
    } else {
        b = y%3;
    }



    if(a==1 && b == 1){
        an = 1;
    }
    if(a == 1 && b == 2){
        an=2;
    }
    if(a == 1 && b == 3){
        an = 3;
    }
        if(a == 2 && b == 1){
        an = 4;
    }
        if(a == 2 && b == 2){
        an = 5;
    }
        if(a == 2 && b == 3){
        an = 6;
    }
        if(a == 3 && b == 1){
        an = 7;
    }
        if(a == 3 && b == 2){
        an = 8;
    }
        if(a == 3 && b == 3){
        an = 9;
    }

    if(an == 1) {
        bool kl = false;
        for(i=1; i<=3; i++){
            for(j=1; j<=3; j++){
                if(g[i][j] == '.'){
                    kl = true;
                    break;
                }
            }
        }
        if(kl == true) {
            for(i=1; i<=3; i++) {
                for(j=1; j<=3; j++) {
                    if(g[i][j]=='.')
                        g[i][j]='!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i==4 || i==7)
                    cout<<endl;
                for(int j=1;j<=9;j++){
                    if(j==4 || j==7)cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        } else {
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if(i <= 3 && j <= 3)
                        continue;
                    if(g[i][j] == '.')
                        g[i][j] = '!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i == 4 || i == 7)
                    cout<<endl;
                for(int j=1; j<=9; j++){
                    if(j == 4 || j == 7)
                        cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        }
        return 0;
    }

    if(an == 2) {
        bool kl = false;
        for(i=1; i<=3; i++){
            for(j=4; j<=6; j++){
                if(g[i][j] == '.'){
                    kl = true;
                    break;
                }
            }
        }
        if(kl == true) {
            for(i=1; i<=3; i++) {
                for(j=4; j<=6; j++) {
                    if(g[i][j]=='.')
                        g[i][j]='!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i==4 || i==7)
                    cout<<endl;
                for(int j=1;j<=9;j++){
                    if(j==4 || j==7)cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        } else {
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if( j > 3 && j <= 6 && i<=3 )
                        continue;
                    if(g[i][j] == '.')
                        g[i][j] = '!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i == 4 || i == 7)
                    cout<<endl;
                for(int j=1; j<=9; j++){
                    if(j == 4 || j == 7)
                        cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        }
        return 0;
    }

    if(an == 3) {
        bool kl = false;
        for(i=1; i<=3; i++){
            for(j=7; j<=9; j++){
                if(g[i][j] == '.'){
                    kl = true;
                    break;
                }
            }
        }
        if(kl == true) {
            for(i=1; i<=3; i++) {
                for(j=7; j<=9; j++) {
                    if(g[i][j]=='.')
                        g[i][j]='!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i==4 || i==7)
                    cout<<endl;
                for(int j=1;j<=9;j++){
                    if(j==4 || j==7) cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        } else {
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if( j > 6 && j <= 9 && i<=3 )
                        continue;
                    if(g[i][j] == '.')
                        g[i][j] = '!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i == 4 || i == 7)
                    cout<<endl;
                for(int j=1; j<=9; j++){
                    if(j == 4 || j == 7)
                        cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        }
        return 0;
    }

    if(an == 4) {
        bool kl = false;
        for(i=4; i<=6; i++){
            for(j=1; j<=3; j++){
                if(g[i][j] == '.'){
                    kl = true;
                    break;
                }
            }
        }
        if(kl == true) {
            for(i=4; i<=6; i++) {
                for(j=1; j<=3; j++) {
                    if(g[i][j]=='.')
                        g[i][j]='!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i==4 || i==7)
                    cout<<endl;
                for(int j=1;j<=9;j++){
                    if(j==4 || j==7) cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        } else {
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if(g[i][j] == '.')
                        g[i][j] = '!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i == 4 || i == 7)
                    cout<<endl;
                for(int j=1; j<=9; j++){
                    if(j == 4 || j == 7)
                        cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        }
        return 0;
    }

        if(an == 5) {
        bool kl = false;
        for(i=4; i<=6; i++){
            for(j=4; j<=6; j++){
                if(g[i][j] == '.'){
                    kl = true;
                    break;
                }
            }
        }
        if(kl == true) {
            for(i=4; i<=6; i++) {
                for(j=4; j<=6; j++) {
                    if(g[i][j]=='.')
                        g[i][j]='!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i==4 || i==7)
                    cout<<endl;
                for(int j=1;j<=9;j++){
                    if(j==4 || j==7) cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        } else {
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if(g[i][j] == '.')
                        g[i][j] = '!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i == 4 || i == 7)
                    cout<<endl;
                for(int j=1; j<=9; j++){
                    if(j == 4 || j == 7)
                        cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        }
        return 0;
    }


        if(an == 6) {
        bool kl = false;
        for(i=4; i<=6; i++){
            for(j=7; j<=9; j++){
                if(g[i][j] == '.'){
                    kl = true;
                    break;
                }
            }
        }
        if(kl == true) {
            for(i=4; i<=6; i++) {
                for(j=7; j<=9; j++) {
                    if(g[i][j]=='.')
                        g[i][j]='!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i==4 || i==7)
                    cout<<endl;
                for(int j=1;j<=9;j++){
                    if(j==4 || j==7) cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        } else {
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if(g[i][j] == '.')
                        g[i][j] = '!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i == 4 || i == 7)
                    cout<<endl;
                for(int j=1; j<=9; j++){
                    if(j == 4 || j == 7)
                        cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        }
        return 0;
    }

            if(an == 7) {
        bool kl = false;
        for(i=7; i<=9; i++){
            for(j=1; j<=3; j++){
                if(g[i][j] == '.'){
                    kl = true;
                    break;
                }
            }
        }
        if(kl == true) {
            for(i=7; i<=9; i++) {
                for(j=1; j<=3; j++) {
                    if(g[i][j]=='.')
                        g[i][j]='!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i==4 || i==7)
                    cout<<endl;
                for(int j=1;j<=9;j++){
                    if(j==4 || j==7) cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        } else {
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if(g[i][j] == '.')
                        g[i][j] = '!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i == 4 || i == 7)
                    cout<<endl;
                for(int j=1; j<=9; j++){
                    if(j == 4 || j == 7)
                        cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        }
        return 0;
    }

            if(an == 8) {
        bool kl = false;
        for(i=7; i<=9; i++){
            for(j=4; j<=6; j++){
                if(g[i][j] == '.'){
                    kl = true;
                    break;
                }
            }
        }
        if(kl == true) {
            for(i=7; i<=9; i++) {
                for(j=4; j<=6; j++) {
                    if(g[i][j]=='.')
                        g[i][j]='!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i==4 || i==7)
                    cout<<endl;
                for(int j=1;j<=9;j++){
                    if(j==4 || j==7) cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        } else {
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if(g[i][j] == '.')
                        g[i][j] = '!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i == 4 || i == 7)
                    cout<<endl;
                for(int j=1; j<=9; j++){
                    if(j == 4 || j == 7)
                        cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        }
        return 0;
    }

            if(an == 9) {
        bool kl = false;
        for(i=7; i<=9; i++){
            for(j=7; j<=9; j++){
                if(g[i][j] == '.'){
                    kl = true;
                    break;
                }
            }
        }
        if(kl == true) {
            for(i=7; i<=9; i++) {
                for(j=7; j<=9; j++) {
                    if(g[i][j]=='.')
                        g[i][j]='!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i==4 || i==7)
                    cout<<endl;
                for(int j=1;j<=9;j++){
                    if(j==4 || j==7) cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        } else {
            for(int i=1; i<=9; i++){
                for(int j=1; j<=9; j++){
                    if(g[i][j] == '.')
                        g[i][j] = '!';
                }
            }
            for(int i=1; i<=9; i++) {
                if(i == 4 || i == 7)
                    cout<<endl;
                for(int j=1; j<=9; j++){
                    if(j == 4 || j == 7)
                        cout<<" ";
                    cout<<g[i][j];
                } cout<<endl;
            }
        }
        return 0;
    }


    return 0;
}

