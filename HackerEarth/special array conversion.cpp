#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<cassert>
using namespace std;
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define ll long long
//useful constants
#define inf (int)1e9
#define infll (ll)1e16
#define eps 1e-6
// useful hardware instructions
#define bitcount __builtin_popcount
#define gcd _gcd
// useful container manipulations
#define mp make_pair
#define llu long long unsigned
#define ld long
#define pb push_back
#define getchar_unlocked() getchar()
#define putchar_unlocked(x) putchar(x)

int scan_d() {
	int ip = getchar_unlocked(), ret = 0, flag = 1;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		if (ip == '-') {
			flag = -1;
			ip = getchar_unlocked();
			break;
		}
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return flag * ret;
}
ld scan_ld() {
	int ip = getchar_unlocked(), flag = 1;
	ld ret = 0;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		if (ip == '-') {
			flag = -1;
			ip = getchar_unlocked();
			break;
		}
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return flag * ret;
}
ll scan_ll() {
	int ip = getchar_unlocked(), flag = 1;
	ll ret = 0;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		if (ip == '-') {
			flag = -1;
			ip = getchar_unlocked();
			break;
		}
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return flag * ret;
}
llu scan_llu() {
	int ip = getchar_unlocked();
	llu ret = 0;
	for (; ip < '0' || ip > '9'; ip = getchar_unlocked())
		;
	for (; ip >= '0' && ip <= '9'; ip = getchar_unlocked())
		ret = ret * 10 + ip - '0';
	return ret;
}
void print_d(int n) {
	if (n < 0) {
		n = -n;
		putchar_unlocked('-');
	}
	int i = 10;
	char output_buffer[10];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 10);
}
void print_ld(ld n) {
	if (n < 0) {
		n = -n;
		putchar_unlocked('-');
	}
	int i = 11;
	char output_buffer[11];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 11);
}
void print_ll(ll n) {
	if (n < 0) {
		n = -n;
		putchar_unlocked('-');
	}
	int i = 21;
	char output_buffer[21];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 21);
}
void print_llu(llu n) {
	int i = 21;
	char output_buffer[21];
	do {
		output_buffer[--i] = (n % 10) + '0';
		n /= 10;
	} while (n);
	do {
		putchar_unlocked(output_buffer[i]);
	} while (++i < 21);
}
bool prime[1000006];
void seive() {
    for(int i=0;i<1000006;i++){
        prime[i]=false;
    }
    prime[1]=true;
    for(ll i = 2; i < 1000006; i++) {
        if(prime[i] == false){
            for(ll j = i*i; j < 1000006; j += i) {
                prime[j] = true;
            }
        }
    }
}
bool comp(int x, int y) {
    return ( x > y );
}
int main() {
    seive();
    int n,tmp;
    n = scan_d();
    vector<int> pr;
    vector<int> non_prime;
    for(int i=0; i<n; i++) {
        tmp = scan_d();
        if(prime[tmp] == false) {
            pr.pb(tmp);
        } else {
            non_prime.pb(tmp);
        }
    }
    sort(pr.begin(), pr.end());
    sort(non_prime.begin(), non_prime.end(), comp);
    for(int i=0; i < pr.size(); i++) {
        print_d(pr[i]);
        printf(" ");
    }
    for(int j=0; j < non_prime.size(); j++){
        print_d(non_prime[j]);
        printf(" ");
    }
        printf("\n");
    return 0;
}
