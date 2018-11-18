#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    unordered_map<int,int> un_mapp;
    unordered_map<int,vector<int> > un_mapp2;

    un_mapp[1]++;
    un_mapp[2]++;
    un_mapp[3]++;

    cout<<un_mapp.size()<<endl;
    un_mapp.erase(un_mapp2.begin(),un_mapp2.end());
    cout<<un_mapp.size()<<endl;

    return 0;
}