#include<bits/stdc++.h>
using namespace std;
#define mx 100005
bool prime[mx];
void seive() {
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(long long i=0;i<mx;i++){
        if(prime[i] == true){
            for(long long j=2*i;j<mx;j+=i){
                prime[j]=false;
            }
        }
    }
}
int main() {
    seive();
    int n;
    cin>>n;
    int tmp;
    vector<vector<int> > en;
    bool flag;
    for(int i=0;i<n;i++){
        cin>>tmp;
    }
    cout<<"Amit is Pendu"<<endl;
    return 0;
}
