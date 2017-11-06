 #include<bits/stdc++.h>
 using namespace std;
 int main() {
    string s;
    cin>>s;

    stack<int> st;
    unordered_map<int,int> un;

    st.push(-1);
    int max_=INT_MIN;

    for(int i=0; i<s.length(); i++) {

        if(s[i] == '('){
            st.push(i);
		} else {
            st.pop();

            if(!st.empty()){

				if(max_ <= (i - st.top())){
                    max_ = (i - st.top());
                    un[max_]++;
				}
            } else {
                st.push(i);
            }
		}
    }

    if(max_ != INT_MIN)
		printf("%d %d\n", max_, un[max_]);
	else
        printf("0 1\n");

    return 0;
 }
