/*
    author    : MishkatIT
    created   : Wednesday 2024-03-27-00.37.53
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

vector<pair<int, int>> tree; // sum, max

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
            tree[node] = {v[s], v[s]};
            return ;
        }
        int mid = (s + e) / 2;
        build(v, 2 * node, s, mid);
        build(v, 2 * node + 1, mid + 1, e);
        tree[node].first = tree[2 * node].first + tree[2 * node + 1].first;
        tree[node].second = max({tree[2 * node].second, tree[2 * node + 1].second, tree[node].first});
    }

    ll query(int node, int s, int e, int l, int r)
    {
        if (e < l || r < s) return -linf;
        if (l <= s && e <= r) return tree[node].second;
        int mid = (s + e) / 2;
        return  max(query(2 * node, s, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
    }
    ll query(int l, int r)
    {
        return query(1, 0, n - 1, l - 1, r - 1);
    }
};


int main()
{
    fio;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    segmentTree st(v);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
    return 0;
}


