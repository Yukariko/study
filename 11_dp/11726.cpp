#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 10007;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> d(N+1);
    d[1] = 1;
    d[2] = 2;
    for (int i=3; i <= N; i++)
        d[i] = (d[i - 1] + d[i - 2]) % MOD;

    cout << d[N] << endl;

    return 0;
}
