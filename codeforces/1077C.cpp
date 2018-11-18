#include<iostream>
#include<vector>
using namespace std;

int a[200005];
int c[1000006];

int main(){
    int n;
    cin>>n;
    int largest=-1,second_largest=-1,temp;
    long long sum=0;
    memset(c,0,sizeof(c));
    vector<int> ans;

    for(int i=0; i<n; i++){
        cin>>a[i];
        c[a[i]]+=1;
        if(largest < a[i]){
            largest = a[i];
        }
        sum+=a[i];
    }

    if(c[largest]>1){
        second_largest=largest;
    } else {
        for(int i=0;i<n;i++){
            if(second_largest<a[i] && a[i]!=largest){
                second_largest=a[i];
            }
        }
    }

    long long one,two;
    for(int i=0;i<n;i++){
        temp = a[i];
        sum = sum - temp;
        c[temp]--;

        if(c[largest]==0){
            one = second_largest;
            two = (sum - one);
            if(one == two){
                ans.push_back(i+1);
            }
        } else {
            one = largest;
            two = (sum - one);
            if(one == two){
                ans.push_back(i+1);
            }
        }

        //put back
        c[temp]++;
        sum = sum + temp;
    }

    if(ans.size()==0){
        cout<<"0"<<endl;
        cout<<" "<<endl;
    } else {
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }cout<<endl;
    }

    return 0;
}