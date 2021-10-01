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

    const int MAX_N = 1000000;
    vector<int> f(MAX_N + 1);
    for (int i=1; i <= MAX_N; i++) {
        for (int j=i; j <= MAX_N; j += i) {
            f[j] += i;
        }
    }

    vector<ll> g(MAX_N + 1);
    for (int i=1; i <= MAX_N; i++)
        g[i] = g[i-1] + f[i];

    while (T--) {
        int N;
        cin >> N;
        cout << g[N] << endl;
    }

    return 0;
}
