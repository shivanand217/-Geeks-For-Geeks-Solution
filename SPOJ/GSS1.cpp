#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define fck std::ios::sync_with_stdio(false);
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

struct SegmentTreeNode {
    int prefixMaxSum, suffixMaxSum, maxSum, sum;

    void assignLeaf(int value) {
        prefixMaxSum = suffixMaxSum = maxSum = sum = value;
    }

    void merge_(SegmentTreeNode& left, SegmentTreeNode& right){
        sum = left.sum + right.sum;
        prefixMaxSum=max(left.prefixMaxSum, left.sum+right.prefixMaxSum);
        suffixMaxSum=max(right.suffixMaxSum, right.sum+left.suffixMaxSum);
        maxSum=max(prefixMaxSum, max(suffixMaxSum, max(left.maxSum,max(right.maxSum,left.suffixMaxSum+right.prefixMaxSum))));
    }

    int getValue(){
        return maxSum;
    }
};

template<class T, class V>
class SegmentTree {
    SegmentTreeNode* nodes;
    int N;

public:
    SegmentTree(T arr[], int N){
        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeMemory(N)];
        buildTree(arr, 1, 0, N-1);
    }

    ~SegmentTree() {
        delete[] nodes;
    }

    int getValue(int lo, int hi){
        SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
        return result.getValue();
    }

private:
    void buildTree(T arr[], int stIndex, int lo, int hi){
        if(lo == hi){
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int left = 2*stIndex;
        int right = left+1;
        int mid = (lo+hi)/2;

        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid+1, hi);
        nodes[stIndex].merge_(nodes[left], nodes[right]);
    }

    SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi){
        if(left == lo && right == hi){
            return nodes[stIndex];
        }

        int mid = (left + right)/2;
        if(lo > mid)
            return getValue(2*stIndex+1, mid+1, right, lo, hi);

        if(hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);

        SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
        SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
        SegmentTreeNode result;
        result.merge_(leftResult, rightResult);

        return result;
    }

    int getSegmentTreeMemory(int N){
        int size_=1;
        for(; size_ < N; size_<<=1);
        return (size_<<1);
    }
};

int main() {

    int n, i, A[50002], m, x, y;
    scanf("%d", &n);

    for(i=0; i < n; i++){
        scanf("%d", &A[i]);
    }
    SegmentTree<int,int> st(A, n);
    scanf("%d",&m);
    for(i=0; i<m; ++i){
        scanf("%d %d", &x, &y);
        x--; y--;
        printf("%d\n", st.getValue(x,y));
    }

    return 0;
}
