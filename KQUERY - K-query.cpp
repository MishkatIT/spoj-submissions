/*
    author    : MishkatIT
    created   : Wednesday 2024-03-27-00.04.10
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

vector<vector<int>> tree;

class segmentTree
{
public:
    int n;
    segmentTree(vector<int>& v)
    {
        n = v.size();
        tree.resize(4 * n);
        build(v, 1, 0, n - 1);
    }
    void build(vector<int>& v, int node, int s, int e)
    {
        if (s == e) {
            tree[node].push_back(v[s]);
            return;
        }
        int mid = (s + e) / 2;
        build(v, 2 * node, s, mid);
        build(v, 2 * node + 1, mid + 1, e);
        tree[node].insert(tree[node].end(), tree[2 * node].begin(), tree[2 * node].end());
        tree[node].insert(tree[node].end(), tree[2 * node + 1].begin(), tree[2 * node + 1].end());
        sort(tree[node].begin(), tree[node].end());
    }

    int query(int node, int s, int e, int l, int r, int val)
    {
        if (e < l || r < s) return 0;
        if (l <= s && e <= r) {
            return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
        }
        int mid = (s + e) / 2;
        return query(2 * node, s, mid, l, r, val) + query(2 * node + 1, mid + 1, e, l, r, val);
    }
    int query(int l, int r, int val)
    {
        return query(1, 0, n - 1, l - 1, r - 1, val);
    }

};

int main()
{
    fio;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    int q;
    cin >> q;
    segmentTree st(v);
    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << st.query(i, j, k) << '\n';
    }
    return 0;
}


