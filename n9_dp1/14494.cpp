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
    int N, M;
    cin >> N >> M;

    const int mod = 1e9 + 7;
    vector<vector<int>> d(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
      d[i][0] = 1;
    }
    for (int i = 0; i < M; i++) {
      d[0][i] = 1;
    }
    for (int i = 1; i < N; i++) {
      for (int j = 1; j < M; j++) {
        d[i][j] = (1LL * d[i][j - 1] + d[i - 1][j] + d[i - 1][j - 1]) % mod;
      }
    }

    cout << d[N - 1][M - 1] << endl;

    return 0;
}
