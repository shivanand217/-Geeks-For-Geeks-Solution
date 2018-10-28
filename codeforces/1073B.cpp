#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int found[200005];
int b[200005];

int main() {
    int n,temp,count=0;
    cin>>n;
    
    deque<int> my_deque;
    for(int i=1;i<=n;i++){ 
        cin>>temp;
        found[temp]=0;
        my_deque.push_back(temp);
    }

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        count=0;
        temp=b[i];
        if(found[temp]==1){
            cout<<"0 ";
        } else {
            int top=-1;
            while(top != temp){
                top=my_deque.front();
                my_deque.pop_front();
                count++;
                found[top]=1;
            }
            cout<<count<<" ";
        }
    }

    return 0;
}