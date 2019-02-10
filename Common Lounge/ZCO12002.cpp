#include<bits/stdc++.h>
using namespace std;

int main(){ 
    vector<int> V,W;
    vector<pair<int,int> > times;

    int best_time = INT_MAX, N, X, Y, start, end, temp, value, low, high, mid, current1, current2;
    cin>>N>>X>>Y;

    for(int i=0; i<N; i++){
        cin>>start>>end;
        times.push_back(make_pair(start,end));
    }
    
    for(int i=0; i<X; i++){
        cin>>temp;
        V.push_back(temp);
    }

    for(int j=0; j<Y; j++){
        cin>>temp;
        W.push_back(temp);
    }

    sort(V.begin(), V.end()); 
    sort(W.begin(), W.end());

    for(int i=0; i<times.size(); i++){
        start = times[i].first;
        end = times[i].second;
        current1 = -1, current2 = -1;
        low = 0, high = X-1;

        while(low <= high){
            mid = low + (high - low)/2;
            if(V[mid] > start){
                high = mid - 1;
            } else {
                current1 = mid;
                low = mid + 1;
            }
        }

        if(current1 != -1){
            low = 0, high = Y-1;
            while(low <= high){
                mid = low + (high - low)/2;
                if(W[mid] < end){
                    low = mid+1;
                } else {
                    current2 = mid;
                    high = mid - 1;
                }
            }
        }

        if(current1 != -1 && current2 != -1){
            value = (W[current2] - V[current1] + 1);
            if(best_time > value){
                best_time = value;
            }
        }
    }
    cout<<best_time<<endl;

    return 0;
}
