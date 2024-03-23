/*
    author    : MishkatIT
    created   : Friday 2024-03-22-03.22.44
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

int main()
{
    fio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n - 1);
        for (auto& i : v) {
            cin >> i;
        }
        vector<int> ans(n + 1, 1);
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == 1) {
                ans[i + 1]++;
            } else if(v[i] == 2 && ans[i] != 1) {
                ans[i]++;
            } else {
                ans[i + 1] = ans[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i]  << " \n"[i == n - 1];
        }
        if (ans.back() <= 0) ans.back() = abs(ans.back()) + 1;
        for (int i = n - 2; i >= 0; i--) {
            if (ans[i] <= 0) {
                if (v[i] == 0) {
                    ans[i] = ans[i + 1];
                }
                if (v[i] == 1) {
                    ans[i + 1] = max(ans[i + 1], ans[i] + 1);
                }
                if (v[i] == 2) {
                    ans[i] = max(ans[i], ans[i + 1] + 1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i]  << " \n"[i == n - 1];
        }
    }
    return 0;
}


