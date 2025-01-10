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

    vector<int> d(N + 1);
    for (int i = 2; i <= N; i++) {
      for (int j = 1; j <= i / 2; j++) {
        int l = j, r = i - j;
        d[i] = max(d[i], l * r + d[l] + d[r]); 
      }
    }

    cout << d[N] << endl;

    return 0;
}
