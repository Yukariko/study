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
    int R, C, W;
    cin >> R >> C >> W;
    
    int N = max(R, C) + W;
    vector<vector<int>> d(N + 1, vector<int>(N + 1));
    d[1][1] = 1;
    for (int i = 2; i <= N; i++) {
      d[i][1] = d[i][i] = 1;
      for (int j = 2; j <= i - 1; j++) {
        d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
      }
    }

    int ans = 0;
    for (int i = 0; i < W; i++) {
      for (int j = 0; j <= i; j++) {
        ans += d[i + R][j + C];
      }
    }

    cout << ans << endl;
    return 0;
}
