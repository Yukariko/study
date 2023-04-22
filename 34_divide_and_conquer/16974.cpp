#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

pair<ll, ll> cache[51];

ll solve(int n, ll& x)
{
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        x -= 1;
        return 1;
    }

    auto& [total, patties] = cache[n];
    if (total > 0 && x >= total) {
        x -= total;
        return patties;
    }

    ll bef = x;
    x -= 1;
    ll cnt = solve(n - 1, x);
    if (x > 0) {
        cnt += 1;
        x -= 1;
    }
    cnt += solve(n - 1, x);
    if (x > 0) {
        x -= 1;
        total = bef - x;
        patties = cnt;
    }
    return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    ll X;
    cin >> N >> X;

    cout << solve(N, X) << endl;

	return 0;
}
