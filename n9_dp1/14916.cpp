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

  const int inf = 1e8;
  vector<int> d(N + 1, inf);
  d[0] = 0;
  d[2] = 1;
  d[4] = 2;
  for (int i = 5; i <= N; i++) {
    d[i] = min(d[i - 2], d[i - 5]) + 1;
  }

  if (d[N] == inf) {
    cout << -1 << endl;
  } else {
    cout << d[N] << endl;
  }

  return 0;
}
