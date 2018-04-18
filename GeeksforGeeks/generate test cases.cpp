#include<bits/stdc++.h>
using namespace std;

/** using function generate and generate_n **/

int randomize()
{
    return (rand() % 1000);
}

int main()
{
    // every time seed NULL so that programs generates different values every time
    srand(time(NULL));

    vector<int> v(10);
    /*generate(v.begin(),v.end(),randomize);

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl;
*/


    generate_n(v.begin(), 6, randomize);

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
