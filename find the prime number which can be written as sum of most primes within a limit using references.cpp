#include<bits/stdc++.h>
using namespace std;

void seive_2(int n, vector<int> &prime)
{
    int new_ = (n-2)/2;

    int *marked = (int*)malloc((new_)*sizeof(int));
    memset(marked, false, sizeof(marked));

    for(int i=1; i<=new_; i++)
    {
        for(int j=i; (i+j+2*i*j)<=new_; j++)
        {
            marked[i+j+2*i*j] = true;
        }
    }

    prime.push_back(2);

    for(int i=1; i<=new_; i++)
    {
        if(marked[i] == false)
        {
            prime.push_back(2*i+1);
        }
    }
}

int solve_for_answer(int limit, vector<int> prime, int prefix_sum[])
{
    int prime_num = -1;
    int max_ = -1;
    int val;

    for(int i=0; i<=limit; i++)
    {
        for(int j=0; j<=i; i++)
        {
         int  val = prefix_sum[i] - prefix_sum[j];

            if(val > limit)break;
            if(binary_search(prime.begin(), prime.end(), val))
            {
          s      if(max_ < (i-j+1))
                {
                    max_ = (i-j+1);
                    prime_num = val;
                }
            }
        }
    }

return prime_num;
}

void solve(int arr[], int n, int size_)
{
    vector<int> prime;
    seive_2(n, prime);
try{
    // creating the prefix prime array
    int prefix_prime[prime.size()];
    prefix_prime[0] = prime[0];

    for(int i=1; i<=prime.size()-1; i++)
    {
        prefix_prime[i] = prefix_prime[i-1] + prime[i];
    }

    int ans;
    for(int i=0; i<size_; i++)
    {
        ans = solve_for_answer(arr[i] , prime, prefix_prime);
        if(ans == -1)
        {
            cout<<"no answer"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}
catch(exception e)
{
cout<<"exception"<<endl;
}

}

int main()
{
    int ma=-1;
    int arr[] = {10, 30, 40, 50, 1000};
    int n = sizeof(arr)/sizeof(arr[0]);

    ma = 1000;

    solve(arr, ma, n);

    return 0;
}
