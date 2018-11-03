#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int test;
    cin>>test;

    string s;
    int rotation,_remainder;
    string first,sec;

    while(test--){
        first="";
        sec="";
        cin>>s;
        cin>>rotation;
        _remainder = rotation%(s.length());

        if(rotation < s.length()){
            int i;
            for(i=0;i<s.length();i++){
                if(i == _remainder){
                    break;
                }
                sec+=s[i];
            }
            while(i<s.length()){
                first+=s[i];
                i++;
            }
            cout<<first<<sec<<endl;
        } else {
            if(_remainder==0){
                cout<<s<<endl;
            } else {
                            int i;
            for(i=0;i<s.length();i++){
                if(i == _remainder){
                    break;
                }
                sec+=s[i];
            }
            while(i<s.length()){
                first+=s[i];
                i++;
            }
            cout<<first<<sec<<endl;
            }
        }
    }

    return 0;
}