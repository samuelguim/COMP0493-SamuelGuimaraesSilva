#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) {
        n = size + 1;
        bit.assign(n, 0);
    }
    
    FenwickTree(vector<int>& arr) {
        n = arr.size() + 1;
        bit.assign(n, 0);
        build(arr);
    }
    
    void build(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            update(i, arr[i]);
        }
    }
    
    void update(int idx, int val) {
        idx++; 
        while (idx < n) {
            bit[idx] += val;
            idx += idx & -idx; 
        }
    }
    
    int query(int idx) {
        int soma = 0;
        idx++; 
        while (idx > 0) {
            soma += bit[idx];
            idx -= idx & -idx; 
        }
        return soma;
    }
    
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};