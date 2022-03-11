#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A, B;
    while (cin >> N >> A >> B, N) {
        vector<tuple<int, int, int>> a(N);
        for (auto& [k, da, db] : a) {
            cin >> k >> da >> db;
        }
        sort(a.begin(), a.end(), [](auto& p, auto& q) {
            return get<1>(p) - get<2>(p) < get<1>(q) - get<2>(q);
        });

        int ans = 0;
        for (int i=N-1; i >= 0; i--) {
            auto& [k, da, db] = a[i];
            if (B > 0 && da >= db) {
                int cnt = min(B, k);
                B -= cnt;
                ans += cnt * db;
                k -= cnt;
            } else {
                break;
            }
        }

        for (auto& [k, da, db] : a) {
            if (A > 0) {
                int cnt = min(k, A);
                k -= cnt;
                A -= cnt;
                ans += da * cnt;
            }
            if (k > 0 && B > 0) {
                B -= k;
                ans += db * k;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

