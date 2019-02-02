#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define maxx 10004

void divisor(int n) {
    int cnt = 0;
    for(int i=1; i*i <= n; i++) {
        if(n % i == 0){
            if(n / i == i){
                cnt++;
            } else {
                cnt+=2;
            }
        }
    }
}

int main() {
    int n,first=INT_MIN,largest=INT_MIN,temp;
    cin>>n;
<<<<<<< HEAD
    
=======

>>>>>>> ae806847d9a5f18c09f4ebcf59375cc6abe8db71
    vector<int> vec;
    vector<int> :: iterator it;
    
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
        if(temp > first){
            first = temp;
        }
    }

<<<<<<< HEAD
=======

>>>>>>> ae806847d9a5f18c09f4ebcf59375cc6abe8db71
    for(int i=1; i<=first; i++){
        if(first % i == 0){
            it = find(vec.begin(), vec.end(), i);
            vec.erase(it);
        }
    }

    sort(vec.begin(), vec.end());
    cout<<first<<" "<<vec[vec.size()-1]<<endl;

    return 0;
}