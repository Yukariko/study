#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N;
int a[1024][1024];

int solve(int sy, int sx, int sz) {
    if (sz == 1) {
        return a[sy][sx];
    }

    sz /= 2;
    int res[] = {
        solve(sy, sx, sz),
        solve(sy + sz, sx, sz),
        solve(sy, sx + sz, sz),
        solve(sy + sz, sx + sz, sz)
    };
    nth_element(&res[0], &res[1], &res[4]);
    return res[1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;

    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve(0, 0, N) << endl;

	return 0;
}
