#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int d[10001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    double D;

    while (cin >> N >> D, N != 0) {
        int M = (D + 1e-6) * 100;
        int ans = 0;

        memset(d, 0, sizeof(d));
        for (int i=0; i < N; i++) {
            int C;
            cin >> C >> D;

            int m = (D + 1e-6) * 100;

            for (int j=m; j <= M; j++) {
                d[j] = max(d[j], d[j - m] + C);
                ans = max(ans, d[j]);
            }
        }

        cout << ans << endl;

    }

	return 0;
}
