/*
    author    : MishkatIT
    created   : Saturday 2024-03-23-19.54.24
*/

#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';

using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> v[i];
        }
        vector<int> ans(n, 1);

        for (int i = 1; i < n; i++) {
            if (v[i - 1] == 0) {
                ans[i] = ans[i - 1];
            } else if (v[i - 1] == 1) {
                ans[i] = ans[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (v[i] == 0) {
                ans[i] = max(ans[i], ans[i + 1]);
            } else if (v[i] == 2) {
                ans[i] = max(ans[i], ans[i + 1] + 1);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}

