#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N;
int a[1001];
int cache[1001][1001];

int solve(int pos, int last)
{
    if (pos == N) {
        return 0;
    }

    int& ret = cache[pos][last];
    if (ret != -1) {
        return ret;
    }

    ret = solve(pos + 1, last);
    if (last < a[pos]) {
        ret = max(ret, a[pos] + solve(pos + 1, a[pos]));
    }

    return ret;
}

int iterative()
{
    vector<int> d(N);
    for (int i=0; i < N; i++) {
        d[i] = a[i];
        for (int j=0; j < i; j++) {
            if (a[j] < a[i]) {
                d[i] = max(d[i], d[j] + a[i]);
            }
        }
    }

    int ans = 0;
    for (int i=0; i < N; i++)
        ans = max(ans, d[i]);
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

    cout << iterative() << endl;

    //cout << solve(0, 0) << endl;

    return 0;
}
