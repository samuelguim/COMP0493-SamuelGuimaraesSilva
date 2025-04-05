#include <vector>
#include <limits>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;
    int n;
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1]; // Soma
        }
    }
    
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (end - start + 1);
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    int query_sum(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return query_sum(2 * node, start, mid, l, r) + 
               query_sum(2 * node + 1, mid + 1, end, l, r);
    }
    
    void update_range(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (r < start || end < l) {
            return;
        }
        if (l <= start && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_range(2 * node, start, mid, l, r, val);
        update_range(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    void update_point(int node, int start, int end, int idx, int val) {
        push(node, start, end);
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update_point(2 * node, start, mid, idx, val);
        } else {
            update_point(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        lazy.assign(4 * n, 0);
    }
    
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }
    
    int query_sum(int l, int r) {
        return query_sum(1, 0, n - 1, l, r);
    }
    
    void update(int idx, int val) {
        update_point(1, 0, n - 1, idx, val);
    }
    
    void update(int l, int r, int val) {
        update_range(1, 0, n - 1, l, r, val);
    }
};