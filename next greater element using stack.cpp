#include<bits/stdc++.h>
using namespace std;

#define maxn 1002
int a[maxn];

void next_greater_element(stack<int> &s, vector<pair<int,int> > &ans, int n)
{
    s.push(a[0]);

    int next;
    int ele;

	for(int i=1; i < n; i++)
	{
        next = a[i];

        if(!s.empty())
		{
			ele = s.top();
			s.pop();

        while(ele < next)
		{
            ans.push_back(make_pair(ele, next));
				if(s.empty())
					break;

			ele = s.top();
			s.pop();
		}

        if(ele > next)
			s.push(ele);
		}

        s.push(next);
	}

    while(!s.empty())
	{
        ele = s.top();
        s.pop();
        ans.push_back(make_pair(ele, -1));
	}
}

int main()
{
    int n;
    cin>>n;

    stack<int> s;
    for(int i=0; i<n; i++)
	{
        cin>>a[i];
	}

	vector<pair<int,int> > ans;

    next_greater_element(s, ans, n);

    for(int i=0; i<ans.size(); i++)
	{
        cout<<ans[i].first<<"->"<<ans[i].second<<endl;
	}

	return 0;
}

/** algorithm is simple

1.first we push the first element in the stack

2.then iterate by second element

3.declare second element as next
	4.pop all the decreasing sequence in compare with next
	means that pop elements from stack until top of stack is lesser than the next
	declare next greater element of all of those as next until stack is not empty

5. if current popped top is less than the next
   then re push the the popped element

6. finally push the next

7. then until stack will not become empty pop out all the elements and the next greater of all of those is -1

**/
