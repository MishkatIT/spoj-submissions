/*
    Author    : MishkatIT
    Created   : Friday 07-06-2024 18:14:26
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
const ll linf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> n >> m;
        if (n > m) {
            cout << 0 << '\n';
            continue;
        }

        ll ans = 0;
        auto findFirstMSB = [&](int m) {
            return (ll)log2(m);
        };
        // debug(findFirstMSB(m));
        for (int i = findFirstMSB(m); i >= 0; i--) {
            if (((1LL << i) & m) && ((1LL << i) & n) == 0) { // m set, n not set at that bit
                ans |= (1LL << i);
            } else {
                if ((1LL << i) & n)
                    break;
            }
        }
        
        while ((ans ^ n) <= m) {
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}