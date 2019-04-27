#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main() {
    int n,position_to_start = -1,position_to_end = -1;
    string s;

    cin>>n; 
    cin>>s;
    
    int mapping[20];
    for(int i=1;i<10;i++){
        cin>>mapping[i];
    }
    for(int i=0;i<s.length();i++){
        if(mapping[s[i]-'0'] > s[i]-'0'){
            position_to_start = i;
            position_to_end = i;
            int j=i;
            while(j<s.length()){
                if(mapping[s[i]-'0'] <= s[i]-'0'){
                    break;
                }
                position_to_end++;
                j++;
            }
            break;
        }
    }
    cout<<"position to start is: "<<position_to_start<<endl;
    cout<<"position to end is: "<<position_to_end<<endl;
    if(position_to_start != -1) {
        for(int i=position_to_start;i<=position_to_end;i++){
            s[i] = mapping[s[i]-'0']+'0';
        }
    }
    cout<<s<<endl;

    return 0;
}