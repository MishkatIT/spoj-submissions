/*
    author    : MishkatIT
    created   : Tuesday 2024-03-26-16.05.20
*/

#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';

using namespace std;
using ll        = long long;
using ld        = long double;
const ll mod    = 1e9 + 7;
const ll N      = 2e5 + 10;
const ll inf    = 1e9;
const ll linf   = 1e18;


vector<array<int, 3>> tree;
vector<int> lazy;

class SegmentTree {
public:
    int n;
    SegmentTree(int x) {
        n = x;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int node, int s, int e) {
        if (s == e) {
            tree[node] = {1, 0, 0};
            return;
        }
        int mid = (s + e) / 2;
        build(2 * node, s, mid);
        build(2 * node + 1, mid + 1, e);
        for (int i = 0; i < 3; i++) {
            tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }

    void propagate(int node, int s, int e) {
        if (lazy[node] != 0) {
            for (int x = 0; x < lazy[node] % 3; x++) {
                rotate(tree[node].begin(), tree[node].end() - 1, tree[node].end());
            }
            if (s != e) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int s, int e, int l, int r, int val) {
        propagate(node, s, e);
        if (e < l || r < s) return;
        if (l <= s && e <= r) {
            lazy[node] += val;
            propagate(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(2 * node, s, mid, l, r, val);
        update(2 * node + 1, mid + 1, e, l, r, val);
        for (int i = 0; i < 3; i++) {
            tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }

    int query(int node, int s, int e, int l, int r) {
        if (e < l || r < s) {
            return 0;
        }
        propagate(node, s, e);
        if (l <= s && e <= r) {
            return tree[node][0];
        }
        int mid = (s + e) / 2;
        return query(2 * node, s, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
    }

    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    fio;
    int n, q;
    cin >> n >> q;
    SegmentTree st(n);
    while(q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 0) {
            st.update(a, b, 1);
        } else {
            cout << st.query(a, b) << '\n';
        }
    }
    return 0;
}


/*

4 5
1 0 3
0 1 2
0 2 3
0 1 2
1 0 3

savior.

*/
