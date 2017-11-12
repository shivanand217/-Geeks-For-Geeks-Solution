#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define fck std::ios::sync_with_stdio(false);
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

#define MAX 200005

int tree[200009], has[200009], save[200009];

void update(int pos , int data){
    while(pos <= MAX){
        tree[pos]+= data;
        pos += (pos & (-pos));
    }
}
int read(int pos){
    int ans = 0;
    while(pos){
        ans += tree[pos];
        pos -= (pos & -pos);
    }
    return ans;
}
struct data{
    int pos , data , hash;
    char type;
};
data d[200009], query[200009];

bool cmp(const data &a , const data &b){
    return a.data == b.data ? a.pos < b.pos : a.data < b.data;
}

int b_search(int k){

    int low = 0 , high = 200000 , mid;
    while(low < high){
        mid = (low + high)>>1;
        if(read(mid) >= k)
            high = mid;
        else
            low = mid+1;
    }
    return low;
}
int main(){
    int q ;
    scanf("%d",&q);
    for(int i = 0 ; i < q ; i++){
        scanf(" %c%d",&d[i].type , &d[i].data);
        d[i].pos = i+1;
    }

    sort(d , d + q , cmp);

    int cnt = 1 , prev = d[0].data;
    d[0].hash = cnt;
    save[cnt]= d[0].data;
    for(int i = 1 ; i < q ; i++)
    {
        if(prev != d[i].data){
            prev = d[i].data;
            cnt++;
            d[i].hash = cnt;
            save[cnt] = d[i].data;
        }
        else
            d[i].hash = cnt;
    }


    for(int i = 0 ; i < q ; i++){
        query[d[i].pos] = d[i];
    }

    cnt = 0;

    for(int i = 1 ; i <= q ; i++){
        if(query[i].type == 'I'){
            if(!has[query[i].hash]){
                cnt++;
                has[query[i].hash] = 1;
                update(query[i].hash , 1);
            }
        }
        else if(query[i].type == 'D'){

            if(has[query[i].hash]){
                cnt--;
                has[query[i].hash] = 0;
                update(query[i].hash , -1);
            }
        }

        else if(query[i].type == 'K'){
            if(query[i].data > cnt)
                printf("invalid\n");
            else
                printf("%d\n",save[b_search(query[i].data)]);
        }
        else
            printf("%d\n",read(query[i].hash - 1));
    }
    return 0;
}
