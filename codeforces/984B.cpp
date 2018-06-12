#include<bits/stdc++.h>
using namespace std;

const int mxn = 306;

#define fast std::ios::sync_with_stdio(false)
int n,m;
bool ans;
char gr[mxn][mxn];

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    ans = true;
    int bomb=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>gr[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            bomb = 0;
            if(gr[i][j] == '*') {
                //continue;
            } else {
                /** check eight directions **/
                if(gr[i][j]=='.') {
                    /** diagonal up left **/
                    if(i-1>=0) {
                        if(j-1>=0) {
                            if(gr[i-1][j-1]=='*') {
                                cout<<"wrong"<<endl;
                                ans = false;
                                break;
                            }
                        }
                    }
                    /** up **/
                    if(i-1>=0) {
                        if(gr[i-1][j]=='*') {
                            cout<<"wrong"<<endl;
                            ans=false;
                            break;
                        }
                    }
                    /** diagonal upper right **/
                    if(i-1>=0&&j+1<m) {
                        if(gr[i-1][j+1]=='*') {
                            cout<<"wrong"<<endl;
                            ans=false;
                            break;
                        }
                    }
                    /** right **/
                    if(j+1<m){
                        if(gr[i][j+1]=='*') {
                            cout<<"wrong"<<endl;
                            ans=false;
                            break;
                        }
                    }
                    /** lower diagonal right **/
                    if(i+1<n&&j+1<m){
                        if(gr[i+1][j+1]=='*') {
                            cout<<"wrong"<<endl;
                            ans=false;
                            break;
                        }
                    }
                    /** down **/
                    if(i+1<n){
                        if(gr[i+1][j]=='*'){
                            cout<<"wrong"<<endl;
                            ans=false;
                            break;
                        }
                    }
                    /** lower diagonal left **/
                    if(i+1<n&&j-1>=0) {
                        if(gr[i+1][j-1]=='*'){
                            cout<<"wrong"<<endl;
                            ans=false;
                            break;
                        }
                    }
                    /** left **/
                    if(j-1>=0) {
                        if(gr[i][j-1]=='*') {
                            cout<<"wrong"<<endl;
                            ans=false;
                            break;
                        }
                    }
                } else {
                    /** check eight direction **/
                    /** diagonal up left **/
                    bomb=0;
                    if(i-1>=0&&j-1>=0) {
                        if(gr[i-1][j-1]=='*') {
                            bomb++;
                        }
                    }
                    /** up **/
                    if(i-1>=0) {
                        if(gr[i-1][j]=='*'){
                            bomb++;
                        }
                    }
                    /** diagonal upper right **/
                    if(i-1>=0&&j+1<m) {
                        if(gr[i-1][j+1]=='*'){
                            bomb++;
                        }
                    }
                    /** right **/
                    if(j+1<m){
                        if(gr[i][j+1]=='*') {
                            bomb++;
                        }
                    }
                    /** lower diagonal right **/
                    if(i+1<n&&j+1<m){
                        if(gr[i+1][j+1]=='*'){
                            bomb++;
                        }
                    }
                    /** down **/
                    if(i+1<n){
                        if(gr[i+1][j]=='*'){
                            bomb++;
                        }
                    }
                    /** lower diagonal left **/
                    if(i+1<n&&j-1>=0) {
                        if(gr[i+1][j-1]=='*'){
                            bomb++;
                        }
                    }
                    /** left **/
                    if(j-1>=0) {
                        if(gr[i][j-1]=='*') {
                           bomb++;
                        }
                    }
                    cout<<bomb<<endl;
                    cout<<gr[i][j]<<endl;
                    if(bomb != gr[i][j]) {
                        ans = false;
                        break;
                    }
                }
            }
        }
        /**if(ans==false) {
            break;
        }**/
    }

    if(ans==false) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }

    return 0;
}
