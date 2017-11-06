#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,tmp,k,sum;
    scanf("%d", &n);
    vector<int> ans;

    for(int i=100; i>=1; i--) {

        tmp = (n - i);
		k = tmp;
        sum=0;
        while(k){
            sum += (k%10);
            k/=10;
        }
        if( (sum+tmp) == n ){
            ans.push_back(tmp);
        }
    }

    if(ans.size() == 0){
        cout<<"0"<<endl;
    } else{
        cout<<ans.size()<<endl;
        for(auto p: ans){
            cout<<p<<endl;
        }
    }

    return 0;
}
