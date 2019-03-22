#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;

    string hour1="",hour2="",min1="",min2="";
    int semi_colon1=0,semi_colon2=0;

    for(int i=0;i<s1.length();i++){
        if(s1[i]==':'){
            semi_colon1++;
        }
        if(semi_colon1 == 0 && s1[i]!=':'){
            hour1+=s1[i];
        } else if(semi_colon1 == 1 && s1[i]!=':'){
            min1+=s1[i];
        }
    }
    for(int i=0;i<s2.length();i++){
        if(s1[i]==':'){
            semi_colon2++;
        }
        if(semi_colon2 == 0 && s2[i]!=':'){
            hour2+=s2[i];
        } else if(semi_colon2 == 1 && s2[i]!=':'){
            min2+=s2[i];
        }
    }

    int _hour1 = 0, _hour2 = 0, _min1 = 0, _min2 = 0;
    _hour1 = stoi(hour1); _min1 = stoi(min1);
    _hour2 = stoi(hour2); _min2 = stoi(min2);

    // cout<<hour1<<":"<<min1<<endl;
    // cout<<hour2<<":"<<min2<<endl;

    //stringstream str()

    return 0;
}