#include<bits/stdc++.h>
using namespace std;
#define mx 605
string en[mx][mx];
void display(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<en[i][j]<<" ";
        } cout<<endl;
    }
}
int main() {
    int t,n,m;
    cin>>t;
    string s,qu;
    int direction;
    /**
        direction-0 = right
        direction-1 = down
        direction-2 = left
        direction-3 = up
    **/
    int right_limit,down_limit,left_limit,up_limit,curr_cell_row,curr_cell_col;
    string ans;
    vector<string> v;
    while(t--) {
        v.clear();
        ans = "";
        direction = 0;
        cin>>n>>m;
        right_limit=m-1;
        down_limit=n-1;
        left_limit=0;
        up_limit=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>s;
                en[i][j]=s;
            }
        }
        cin>>qu;
        curr_cell_row = 0;
        curr_cell_col = 0;
        int inc;
        while(en[curr_cell_row][curr_cell_col] != qu) {
            inc = 0;
            /** go right **/
            if(direction == 0) {
                while(curr_cell_col <= right_limit) {
                    inc++;
                    if(en[curr_cell_row][curr_cell_col] == qu) {
                        v.push_back(en[curr_cell_row][curr_cell_col]);
                        ans += en[curr_cell_row][curr_cell_col];
                        break;
                    } else {
                        ans += en[curr_cell_row][curr_cell_col];
                        curr_cell_col++;
                    }
                }
                if(en[curr_cell_row][curr_cell_col] == qu) {
                    break;
                }
                if(curr_cell_col > right_limit)
                    curr_cell_col--;
                direction++;
                direction %= 4;
                right_limit--;
                curr_cell_row++;
            }
            /** go down **/
            else if(direction == 1) {
                while(curr_cell_row <= down_limit) {
                    inc++;
                    if(en[curr_cell_row][curr_cell_col] == qu) {
                        ans += en[curr_cell_row][curr_cell_col];
                        break;
                    } else {
                        ans += en[curr_cell_row][curr_cell_col];
                        curr_cell_row++;
                    }
                }
                if(curr_cell_row > down_limit)
                    curr_cell_row--;
                direction++;
                direction %= 4;
                down_limit--;
                curr_cell_col--;
            }
            /** go left **/
            else if(direction == 2) {
                while(curr_cell_col >= left_limit) {
                    inc++;
                    if(en[curr_cell_row][curr_cell_col] == qu) {
                        ans += en[curr_cell_row][curr_cell_col];
                        break;
                    } else {
                        ans += en[curr_cell_row][curr_cell_col];
                        curr_cell_col--;
                    }
                }
                if(curr_cell_col < left_limit)
                    curr_cell_col++;
                direction++;
                direction %= 4;
                left_limit++;
                curr_cell_row--;
            }
            /** go up **/
            else if(direction == 3) {
                while(curr_cell_row >= up_limit) {
                    inc++;
                    if(en[curr_cell_row][curr_cell_col] == qu) {
                        ans += en[curr_cell_row][curr_cell_col];
                        break;
                    }
                    ans += en[curr_cell_row][curr_cell_col];
                    curr_cell_row--;
                }
                if(curr_cell_row < up_limit)
                    curr_cell_row++;
                direction++;
                direction %= 4;
                up_limit++;
                curr_cell_col++;
            }
            //cout<<curr_cell_row<<" "<<curr_cell_col<<endl;
            if(inc == 0)
                break;
        }
        cout<<ans<<endl;
        /**if(ans.length() > 0) {
            cout<<ans<<endl;
        } else {
            cout<<"NO"<<endl;
        }**/
    }

    return 0;
}
