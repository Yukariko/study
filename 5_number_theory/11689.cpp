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
    int T;
    cin >> T;

    for (int t=1; t <= T; t++) {
        ll a, b;
        int n;
        cin >> a >> b >> n;

        vector<int> factors;
        for (int i=2; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }

        if (n > 1) factors.push_back(n);

        auto f = [&](ll n) {
            ll res = n;
            int mask = 1 << factors.size();
            for (int i=1; i < mask; i++) {
                int m = 1;
                int cnt = 0;
                for (int j=0; (1 << j) <= i; j++) {
                    if (i & (1 << j)) {
                        m *= factors[j];
                        cnt++;
                    }
                }
                if (cnt & 1) res -= n / m;
                else res += n / m;
            }
            return res;
        };

        cout << "Case #" << t << ": " <<  f(b) - f(a-1) << endl;
    }

    return 0;
}
