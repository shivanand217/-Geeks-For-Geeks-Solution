#include<bits/stdc++.h>
#define mx 600
using namespace std;
int r,c;
char grid[mx][mx];
bool an;

void show() {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout<<grid[i][j];
        }   cout<<endl;
    }
}

bool check(int i,int j) {
    if(i == 0) {
        if(j == 0) {
            if(grid[i+1][j] == 'W' || grid[i][j+1]=='W')
                return true;
        } else if(j == c-1) {
            if(grid[i+1][j] == 'W' || grid[i][j-1]=='W')
                return true;
        } else {
            if(grid[i+1][j]=='W'||grid[i][j-1]=='W'||grid[i][j+1]=='W')
                return true;
        }
    } else if(i == r-1) {
        if(j == 0) {
            if(grid[i-1][j]=='W'||grid[i][j+1]=='W')
                return true;
        } else if(j == c-1) {
            if(grid[i-1][j]=='W'||grid[i][j-1]=='W')
                return true;
        } else {
            if(grid[i-1][j]=='W'||grid[i][j-1]=='W'||grid[i][j+1]=='W')
                return true;
        }
    } else {
        if(grid[i-1][j]=='W'||grid[i][j-1]=='W'||grid[i+1][j]=='W'||grid[i][j+1]=='W')
            return true;
    }
        return false;
}

void fill_dogs() {
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j] == 'S'){
                if(i == 0 ) {
                    if(j == 0) {
                        /** check only two directions **/
                        if(grid[i+1][j]=='.')
                            grid[i+1][j]='D';
                        if(grid[i][j+1]=='.')
                            grid[i][j+1]='D';
                    } else if(j == c-1) {
                        /** check only two directions **/
                        if(grid[i+1][j]=='.')
                            grid[i+1][j]='D';
                        if(grid[i][j-1]=='.')
                            grid[i][j-1]='D';
                    } else {
                        /** check three directions **/
                        if(grid[i+1][j]=='.')
                            grid[i+1][j]='D';
                        if(grid[i][j-1]=='.')
                            grid[i][j-1]='D';
                        if(grid[i][j+1]=='.')
                            grid[i][j+1]='D';
                    }
                } else if(i == r-1) {
                    if(j == 0) {
                        /** check only two directions **/
                        if(grid[i-1][j]=='.')
                            grid[i-1][j]='D';
                        if(grid[i][j+1]=='.')
                            grid[i][j+1]='D';
                    } else if(j == c-1) {
                        /** check only two directions **/
                        if(grid[i-1][j]=='.')
                            grid[i-1][j]='D';
                        if(grid[i][j-1]=='.')
                            grid[i][j-1]='D';
                    } else {
                        /** check three directions **/
                        if(grid[i][j-1]=='.')
                            grid[i][j-1]='D';
                        if(grid[i-1][j]=='.')
                            grid[i-1][j]='D';
                        if(grid[i][j+1]=='.')
                            grid[i][j+1]='D';
                    }
                } else {
                    /** check four directions **/
                    if(grid[i-1][j]=='.')
                        grid[i-1][j]='D';
                    if(grid[i+1][j]=='.')
                        grid[i+1][j]='D';
                    if(grid[i][j-1]=='.')
                        grid[i][j-1]='D';
                    if(grid[i][j+1]=='.')
                        grid[i][j+1]='D';
                }
            }
        }
    }
}

int main() {
    int wolf=0, sheep=0;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'S'){
                sheep++;
            }
            if(grid[i][j] == 'W'){
                wolf++;
            }
        }
    }
    if( sheep == 0 || wolf == 0 || (r*c == 1) ) {
        cout<<"Yes"<<endl;
        show();
    } else {
        an = true;

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j]=='S') {
                    if(check(i,j) == true){
                        an = false;
                        break;
                    }
                }
            }
        }

        if(an == false) {
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
            fill_dogs();
            show();
        }
    }

    return 0;
}
