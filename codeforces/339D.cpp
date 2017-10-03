#include<bits/stdc++.h>
using namespace std;

struct SegmentTreeNode {
    int Value;

    void assignLeaf(int value) {
        Value = value;
    }

    void merge1(SegmentTreeNode& left, SegmentTreeNode& right) {
        Value = (left.Value)|(right.Value);
    }

    void merge2(SegmentTreeNode& left, SegmentTreeNode& right) {
        Value = (left.Value)^(right.Value);
    }

    int getValue() {
        return Value;
    }
};

template<class T, class V>
class SegmentTree {

public:
    SegmentTreeNode* nodes;
    int N;

    SegmentTree(int N) {
        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeMemory(N)];
    }

    void update(int index, T value, int n) {
        update(1, 0, N-1, index, value, n);
    }

    void build(T arr[], int n){
    	buildTree(arr, 1, 0, N-1, n);
    }

    void buildTree(T arr[], int stIndex, int lo, int hi, int lev) {

        if(lo == hi){
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int left = 2*stIndex;
        int right = left+1;
        int mid = (lo+hi)/2;

        buildTree(arr, left, lo, mid, lev-1);
        buildTree(arr, right, mid+1, hi, lev-1);

		if((lev&1)){
			nodes[stIndex].merge1(nodes[2*stIndex],nodes[2*stIndex+1]);
		}
		else{
			nodes[stIndex].merge2(nodes[2*stIndex],nodes[2*stIndex+1]);
		}

    }

    int getSegmentTreeMemory(int N){
        int size_=1;
        for(; size_ < N; size_<<=1);
        return (size_<<1);
    }

    // point update
    void update(int stIndex, int lo, int hi, int index, T value, int lev) {
                if(lo == hi){
                    nodes[stIndex].assignLeaf(value);
                    return;
                }

                int left = 2*stIndex;
                int right = left+1;
                int mid = (lo+hi)/2;

                if(index <= mid)
                    update(left, lo, mid, index, value, lev-1);
				else
                    update(right, mid+1, hi, index, value, lev-1);

				if((lev&1)){
					nodes[stIndex].merge1(nodes[2*stIndex],nodes[2*stIndex+1]);
				}
				else{
					nodes[stIndex].merge2(nodes[2*stIndex],nodes[2*stIndex+1]);
				}
	}

};

int main() {

    int n ,m ,p ,b;
    scanf("%d %d", &n, &m);

    int val=(1<<n);
    int a[val];

    for(int i=0; i<val; i++){
        scanf("%d", &a[i]);
    }

    SegmentTree<int,int> st(val);
    st.build(a, n);

    for(int i=0; i<m; i++) {
        scanf("%d %d", &p, &b);
			p--;
        st.update(p, b, n);
        printf("%d\n", st.nodes[1].getValue());
    }

    return 0;
}
