#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){ 
    int n;
    string str;
    string a="";
    bool possible=false;
    cin>>n; cin>>str;
    for(int i=0;i<str.length()-1;i++){
        if(str[i] != str[i+1]){
            a+=str[i];a+=str[i+1];
            break;
        }
    }
    if(a.length() == 2){
        cout<<"YES"<<endl;
        cout<<a<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}