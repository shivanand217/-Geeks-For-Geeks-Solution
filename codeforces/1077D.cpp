#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#define maxx 200005

int c[maxx];
int arr[maxx];

// sort in decreasing order by second value
bool sorrt(pair<int,int> a,pair<int,int> b){
    return (a.second > b.second);
}

int main(){
    int n,k,temp;
    cin>>n>>k;
    memset(c,0,sizeof(c));
    vector<pair<int,int> > vec;
    vector<int> ans;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        c[arr[i]]++;
    }

    for(int i=0;i<n;i++){
        vec.push_back(make_pair(arr[i],c[arr[i]]));
    }
    sort(vec.begin(),vec.end(),sorrt);

    int ele=0;
    for(int i=0;i<vec.size();i++){
        if(ele == k){
            break;
        } else {
            ans.push_back(vec[i].first);
            ele++;
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    } cout<<endl;

    return 0;
}