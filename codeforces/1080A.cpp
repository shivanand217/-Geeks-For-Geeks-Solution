#include<iostream>
using namespace std;

int main(){ 
    int n,k;
    cin>>n>>k;
    
    // 8-B,5-G,2-R
    long long total_blue,total_green,total_red,sheet_blue,sheet_green,sheet_red;
    
    total_blue = 8 * n;
    total_green = 5 * n;
    total_red = 2 * n;

    sheet_blue = total_blue / k;
    sheet_green = total_green / k;
    sheet_red = total_red / k;

    if(total_blue % k != 0){
        sheet_blue+=1;
    }
    if(total_green % k != 0){
        sheet_green+=1;
    }
    if(total_red % k != 0){
        sheet_red+=1;
    }

    long long ans;
    ans = sheet_blue+sheet_green+sheet_red;
    cout<<ans<<endl;

    return 0;
}