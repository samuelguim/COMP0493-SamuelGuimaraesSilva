#include <vector>
#include <limits>
using namespace std;

class SegmentTreeMinMax {
private:
    vector<int> tree_sum;
    vector<int> tree_min;
    vector<int> tree_max;
    vector<int> lazy;
    int n;
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree_sum[node] = arr[start];
            tree_min[node] = arr[start];
            tree_max[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            
            // Soma
            tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
            
            // Mínimo
            tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
            
            // Máximo
            tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
        }
    }
    
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree_sum[node] += lazy[node] * (end - start + 1);
            tree_min[node] += lazy[node];
            tree_max[node] += lazy[node];
            
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
            return tree_sum[node];
        }
        int mid = (start + end) / 2;
        return query_sum(2 * node, start, mid, l, r) + 
               query_sum(2 * node + 1, mid + 1, end, l, r);
    }
    
    int query_min(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (r < start || end < l) {
            return numeric_limits<int>::max();
        }
        if (l <= start && end <= r) {
            return tree_min[node];
        }
        int mid = (start + end) / 2;
        return min(query_min(2 * node, start, mid, l, r),
                   query_min(2 * node + 1, mid + 1, end, l, r));
    }
    
    int query_max(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (r < start || end < l) {
            return numeric_limits<int>::min();
        }
        if (l <= start && end <= r) {
            return tree_max[node];
        }
        int mid = (start + end) / 2;
        return max(query_max(2 * node, start, mid, l, r),
                   query_max(2 * node + 1, mid + 1, end, l, r));
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
        
        tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }
    
    void update_point(int node, int start, int end, int idx, int val) {
        push(node, start, end);
        if (start == end) {
            tree_sum[node] = val;
            tree_min[node] = val;
            tree_max[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update_point(2 * node, start, mid, idx, val);
        } else {
            update_point(2 * node + 1, mid + 1, end, idx, val);
        }
        
        tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }

public:
    SegmentTreeMinMax(int size) {
        n = size;
        tree_sum.resize(4 * n);
        tree_min.resize(4 * n);
        tree_max.resize(4 * n);
        lazy.assign(4 * n, 0);
    }
    
    SegmentTreeMinMax(vector<int>& arr) {
        n = arr.size();
        tree_sum.resize(4 * n);
        tree_min.resize(4 * n);
        tree_max.resize(4 * n);
        lazy.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }
    
    int query_sum(int l, int r) {
        return query_sum(1, 0, n - 1, l, r);
    }
    
    int query_min(int l, int r) {
        return query_min(1, 0, n - 1, l, r);
    }
    
    int query_max(int l, int r) {
        return query_max(1, 0, n - 1, l, r);
    }
    
    void update(int idx, int val) {
        update_point(1, 0, n - 1, idx, val);
    }
    
    void update(int l, int r, int val) {
        update_range(1, 0, n - 1, l, r, val);
    }
};