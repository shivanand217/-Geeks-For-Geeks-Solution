#include<bits/stdc++.h>
using namespace std;

#define fast std::ios::sync_with_stdio(false)

const int mxn = 105;
bool arr[mxn];
int n,k,tmp;

int main() {
    fast;
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    memset(arr, false, sizeof(arr));
    vector<int> ans;

    for(int i=0; i <n; i++) {
        cin>>tmp;
        if(arr[tmp] == false) {
            if(ans.size() == k) {
                continue;
            }
            ans.push_back(i+1);
            arr[tmp]=true;
        }
    }

    if(ans.size() == k) {
        cout<<"YES"<<endl;
        for(auto it =ans.begin(); it!= ans.end(); ++it){
            cout<<*it<<" ";
        } cout<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}
