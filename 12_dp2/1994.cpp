#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N;
int a[2001];
int cache[2001][2001];

int solve(int pos, int bef)
{
    if (pos == N) {
        return 0;
    }

    int& ret = cache[pos][bef];
    if (ret != -1) {
        return ret;
    }
    ret = 0;

    int diff = a[pos] - a[bef];
    int lo = lower_bound(a + pos + 1, a + N, a[pos] + diff) - a;
    if (a[lo] == a[pos] + diff) {
        return ret = 1 + solve(lo, pos);
    }
    return ret;
}

int iterative()
{
    int ans = 1;
    for (int i=0; i < N; i++) {
        cache[i][i] = 1;
        for (int j=0; j < i; j++) {
            cache[i][j] = 2;
            int diff = a[i] - a[j];
            int hi = upper_bound(a, a + j, a[j] - diff) - a - 1;
            if (a[hi] == a[j] - diff) {
                cache[i][j] = max(cache[i][j], cache[j][hi] + 1);
                ans = max(ans, cache[i][j]);
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    memset(cache, -1, sizeof(cache));

    cin >> N;

    for (int i=0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a + N);
    //cout << iterative() << endl;

    int ans = 1;
    for (int i=0; i < N; i++) {
        for (int j=0; j < i; j++) {
            ans = max(ans, 2 + solve(i, j));
        }
    }
    cout << ans << endl;

    return 0;
}
