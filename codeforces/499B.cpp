#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    string s1,s2;

    unordered_map<string,vector<string> > f,s;

    for(int i=0; i<m; i++){
        cin>>s1>>s2;
        f[s1].push_back(s2);
        f[s2].push_back(s1);
    }

    vector<string> lecture;
    for(int i=0; i<n; i++){
		cin>>s1;
        lecture.push_back(s1);
    }

    for(int i=0; i<n; i++){

        if(f[lecture[i]].size()==0){
            if(s[lecture[i]][0].length() < lecture[i].length()){
                lecture[i] = s[lecture[i]][0];
            }
        } else {
            if(f[lecture[i]][0].length() < lecture[i].length()){
                lecture[i] = f[lecture[i]][0];
            }
        }
    }

    for(int i=0; i<lecture.size(); i++){
        cout<<lecture[i]<<" ";
    }cout<<endl;

    return 0;
}
