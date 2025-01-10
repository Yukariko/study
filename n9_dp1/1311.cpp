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
    int N;
    cin >> N;

    vector<vector<int>> a(N, vector<int>(N));
    for (auto& v : a) {
      for (int& n : v) {
        cin >> n;
      }
    }

    const int inf = 1e9;
    vector<int> d(1 << N, inf);

    d[0] = 0;
    for (int i = 0; i < (1 << N); i++) {
      int n = __builtin_popcount(i);
      for (int j = 0; j < N; j++) {
        if (i & (1 << j)) {
          continue;
        }
        d[i | (1 << j)] = min(d[i | (1 << j)], d[i] + a[n][j]);
      }
    }
    
    cout << d[(1 << N) - 1] << endl;

    return 0;
}
