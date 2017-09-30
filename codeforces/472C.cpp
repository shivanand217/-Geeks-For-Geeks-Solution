#include<bits/stdc++.h>
using namespace std;

int main(){

    long n;
	scanf("%ld\n", &n);

    vector<pair<string, string> > nameVec(n);

    for(long p = 0; p < n; p++){
        string first, second;
        cin >> first >> second;
        if(first > second){string temp = first; first = second; second = temp;}
        nameVec[p] = pair<string, string>(first, second);
    }

    vector<long> order(n);

    for(long p = 0; p < n; p++){
        long temp; cin >> temp; order[p] = temp - 1;
    }


    string last = nameVec[order[0]].first;
    string result = "YES";

    for(int p = 0; p < n; p++){
        if(nameVec[order[p]].first >= last){last = nameVec[order[p]].first;}
        else if(nameVec[order[p]].second >= last){last = nameVec[order[p]].second;}
        else{result = "NO"; break;}
    }

	cout << result << std::endl;

    return 0;
}
