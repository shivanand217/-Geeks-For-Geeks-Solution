#include<bits/stdc++.h>
using namespace std;

/**
	lsdijfjisl
	lsdijafjisl->pal
	lsdijfjidsl->not pal
**/

bool pal(string s){
    int i,j;
    i=0;
    j=s.length()-1;
    while(i<=j) {
        if(s[i]!=s[j])
			return false;
		i++;
		j--;
    }
    return true;
}

int main() {
    string s,f,p;
    cin>>s;

	bool ans=true;
	if(s.length()==1) {
        s.insert(0,1,s[0]);
	}
	else if(s.length()==2){
        if(s[0]==s[1]){
            s.insert(1,1,'a');
        } else {
            s.insert(s.length(),1,s[0]);
        }
	} else {
		int i=0,j=s.length()-1;
        if(s[i] != s[j]) {
			f=s;
			f.erase(0,1);
			p=s;
            p.erase(p.length()-1,1);
            if(pal(f)){
                s.insert(s.length(),1,s[0]);
            } else if(pal(p)){
            	s.insert(0,1,s[s.length()-1]);
            } else
				ans=false;
        } else {
            int k=-1;
            while(i<=j) {
                if(s[i] != s[j]){
                    string m,n;
                    m=s;
                    m.insert(j+1,1,s[i]);
                    n=s;
                    n.insert(i,1,s[j]);
                    if(pal(m)) {
						s=m;
                    } else if(pal(n)){
                    	s=n;
                    } else {
                        ans=false;
                    }
					k++;
					break;
				}
					i++;j--;
            }
            if(k==-1){
                if(s.length()%2==0){
                    int kl=s.length()/2;
                    s.insert(kl,1,'a');
                } else {
                    s.insert(s.length()/2,1,s[s.length()/2]);
                }
            }
        }
	}
	if(ans==true) {
        cout<<s<<endl;
	} else {
        cout<<"NA"<<endl;
	}
	return 0;
}
