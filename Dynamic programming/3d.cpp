#include<bits/stdc++.h>
using namespace std;

int main()
{

int a[][2][2] = {
                {
                {1, 2},
                {3, 4}
                },
                {
                {4, 8},
                {5, 2}
                }
                };

for(int i=0; i<2;i ++)
{
    for(int j=0; j<2; j++)
    {
        for(int k=0; k<2; k++)
        {
            cout<<a[i][j][k]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

/**arr[0][0][0] + arr[0][0][1] +
              arr[0][1][1] + arr[1][1][1] **/

    cout<<a[0][0][0]<<" "<<a[0][0][1]<<" "<<a[0][1][1]<<" "<<a[1][1][1]<<endl;

return 0;

}
