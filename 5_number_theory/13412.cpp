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
        int N;
        cin >> N;
        int ans = 0;
        for (int i=1; i * i <= N; i++) {
            if (N % i == 0 && gcd(i, N / i) == 1) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
