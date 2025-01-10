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

    const int mod = 1e9 + 9;
    const int max_n = 1e5;
    vector<vector<int>> d(max_n + 1, vector<int>(3));
    d[1][0] = 1;
    d[2][1] = 1;
    d[3][2] = 1;
    for (int i = 3; i <= max_n; i++) {
      for (int j = 1; j <= 3; j++) {
        for (int k = 1; k <= 3; k++) {
          if (j == k) {
            continue;
          }
          d[i][j - 1] = (d[i][j - 1] + d[i - j][k - 1]) % mod;
        }
      }
    }

    int T;
    cin >> T;
    while (T--) {
      int N;
      cin >> N;
      cout << (1LL * d[N][0] + d[N][1] + d[N][2]) % mod << endl;
    }

    return 0;
}

