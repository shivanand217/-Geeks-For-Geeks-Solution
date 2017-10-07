#include<bits/stdc++.h>
using namespace std;

int main() {

	string s,ans="";
    cin>>s;

    int cnt[26];
    for(int i=0;i<26;i++)
		cnt[i]=0;
    for(int i=0;i<s.length(); i++) {
        cnt[s[i]-'a']++;
    }

	stack<char> st;
	char min_,n;

    for(int i=0; i<s.length(); ) {

        st.push(s[i]);
        cnt[s[i]-'a']--;
        i++;

		min_='z';
        for(int j=25; j>=0; j--){
            if(cnt[j]>0){
                n = j+'a';
                if(min_ > (n)){
                    min_ = (n);
                }
            }
        }

        if(st.top() <= min_) {
            while(1) {
                if(st.empty()){
					break;
                }
                if(st.top()>min_)
					break;

                char k = st.top();
                st.pop();
                ans+=k;

				min_='z';
				for(int j=25; j>=0; j--){
					if(cnt[j]>0){
						n = j+'a';
						if(min_ > (n)){
							min_ = (n);
						}
					}
				}
            }
        }
    }

    while(!st.empty()){
        min_=st.top();
        st.pop();
        ans+=min_;
    }

    cout<<ans<<endl;
	return 0;
}
