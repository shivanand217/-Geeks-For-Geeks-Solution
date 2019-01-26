#include <iostream>
#include <string>
using namespace std;

int  main() {
    string decrypt,encrypt="";
    cin>>decrypt;

    int last, first, len;
    len = decrypt.length();

    // edge case
    if (decrypt.length()==1){
        cout<<decrypt<<endl;
        return 0;
    }

    if(len % 2 == 0) {
        last = decrypt.length()-1;
        first = 0;
    } else {
        last = 0;
        first = decrypt.length()-1;
    }
    
    if(len % 2 == 0) {
        while(first < last) {
            encrypt += decrypt[last];
            encrypt += decrypt[first];
            first++;
            last--;
        }
        if(last == first) {
            encrypt += decrypt[last];
        }
    } else {
        while(first > last) {
            encrypt += decrypt[last];
            encrypt += decrypt[first];
            last++;
            first--;
        }
        if(last == first) {
            encrypt += decrypt[last];
        }
    }

    for(int i=encrypt.length()-1; i>=0; i--){
        cout<<encrypt[i];
    } cout<<endl;

    return 0;
}