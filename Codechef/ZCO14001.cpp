#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;

/**
    1 : Move left
    2 : Move right
    3 : Pick up box
    4 : Drop box
    0 : Quit
**/

int boxes[100005];

int main(){
    int N,H,command;
    cin>>N>>H;

    vector<int> commands;

    for(int i=0; i<N; i++){
        cin>>boxes[i];
    }

    while(1){
        cin>>command;
        if(command==0){
            break;
        }
        commands.push_back(command);
    }

    int current_pointer=0,current_picked=0;
    for(int i=0; i<N; i++){
        if(commands[i]==1){
            if(current_pointer==0){
                continue;
            } else {
                current_pointer-=1;
            }
        } else if(commands[i]==2){
            if(current_pointer==N-1){
                continue;
            } else {
                current_pointer+=1;
            }
        } else if(commands[i]==3){
            if(current_picked==1){
                continue;
            } else {
                if(boxes[current_pointer]>0){
                    current_picked=1;
                    boxes[current_pointer]-=1;
                }
            }
        } else if(commands[i]==4){
            if(current_picked==0){
                continue;
            } else {
                if(boxes[current_pointer]>=H){
                    continue;
                } else {
                    current_picked=0;
                    boxes[current_pointer]+=1;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        cout<<boxes[i]<<" ";
    } cout<<endl;

    return 0;
}