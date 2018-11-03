#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int test,value;
    cin>>test;
    string tmp,ok;
    vector<int> numbers,missing;
    int kTh_missing,count,missing_number,answer,temp;

    while(test--) {
        answer=0;
        numbers.clear();
        missing.clear();
        ok=""; count=0;
        cin>>tmp;

        for(int i=0;i<tmp.length();i++){
            if(tmp[i]==','){
                if(ok.length() != 0){
                    value = stoi(ok);
                    numbers.push_back(value);
                }
                ok="";
            } else {
                ok+=tmp[i];
            }
        }
        if(ok.length() != 0){
            value = stoi(ok);
            numbers.push_back(value);
        }

        cin>>kTh_missing;
        sort(numbers.begin(),numbers.end());

        for(int i=1;i<numbers.size();i++){
            if(numbers[i] - numbers[i-1] != 1){
                missing_number=numbers[i-1]+1;
                count++;
                temp = missing_number;

                while(temp != numbers[i]){
                    missing.push_back(temp);
                    temp++;
                }
                if(count == kTh_missing){
                    answer = missing_number;
                    break;
                }
            }
        }

        if(missing.size() < kTh_missing) {
            cout<<"-1"<<endl;
        } else {
            cout<<missing[kTh_missing-1]<<endl;
        }
    }

    return 0;
}