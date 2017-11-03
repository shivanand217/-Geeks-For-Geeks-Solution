#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

bool comp( pair<int,int> x, pair<int,int> y) {
    return ( x.first > y.first );
}

int startDay[maxn], lectures[maxn], sadness[maxn], lectureTaken[maxn];
vector<pair<int,int> > person;
set<int> days;

int main() {
	int t,n,day,p,x,y;
	long long sum;
	scanf("%d", &t);

    while(t--) {
        person.clear();
        days.clear();

        sum=0;
        scanf("%d %d", &n, &day);
        memset(lectureTaken, 0, sizeof(lectureTaken));

        for(int i=0; i < n; i++) {
            scanf("%d %d %d", &startDay[i], &lectures[i], &sadness[i]);
			startDay[i]--;
        }

        for(int i=0; i<n; i++) {
			person.push_back(make_pair(sadness[i] , i));
        }

        sort(person.begin(), person.end(), comp);
		for(int i=0;i<day;i++)
			days.insert(i);

        for(int i=0; i < person.size(); i++){
                int lec = lectures[person[i].second];
				for(int j=0; j < lec; j++){
                    auto it = days.lower_bound(startDay[person[i].second]);
                    if(it == days.end())
						break;
					else {
                        lectureTaken[person[i].second]++;
                        days.erase(it);
					}
                }
        }
        for(int i=0; i<n; i++) {
			sum += (lectures[i] - lectureTaken[i])*(long long)(sadness[i]);
		}
		printf("%lld\n", sum);
    }
    return 0;
}
