#include<bits/stdc++.h>
using namespace std;

#define mxx 100005
double disc[mxx],price[mxx],qty[mxx];

int main() {
    int t,n;
    cin>>t;
    double increase,loss,discount,temp;

    while(t--) {
        loss = 0.0;
        cin>>n;
        for(int i=0; i < n; i++) {
            cin>>price[i]>>qty[i]>>disc[i];
            temp = price[i];
            increase = (price[i] * (disc[i]/100*1.0));
            price[i] = price[i] + increase;
            discount = (1.0*price[i] * (disc[i]*1.0/100*1.0));
            price[i] -= discount;
            double dec;
            if(price[i] < temp) {
                loss += (temp - price[i])*(qty[i]);
            }
        }

        cout<<fixed<<setprecision(8)<<loss<<endl;
    }

    return 0;
}
