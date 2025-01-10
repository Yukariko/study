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
    const int max_n = 10000;
    vector<int> d(max_n + 1);

    d[0] = 1;
    for (int i = 1; i <= 3; i++) {
      for (int j = i; j <= max_n; j++) {
        d[j] += d[j - i];
      }
    }

    int T;
    cin >> T;
    while (T--) {
      int N;
      cin >> N;
      cout << d[N] << endl;
    }

    return 0;
}
