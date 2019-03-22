// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

bool compare(int x, int y) {
    return x > y;
}

int main() {
    int N,M,num,Q;
    cin>>N>>M;

    vector<long long> multi;
    long long temp;

    for(int i=0; i<N; i++){
        cin>>num;
        multi.push_back(num);
    }

    for(int i=0; i<N; i++){
        temp = multi[i];
        while(temp){
            temp = temp/2;
            if(temp){
                multi.push_back(temp);
            }
        }
    }

    sort(multi.begin(), multi.end(), compare);

    for(int i=0; i<M; i++){
        cin>>Q;
        cout<<multi[Q-1]<<endl;
    }

    return 0;
}
