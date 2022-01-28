#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, K;
double a[2501];
double cache[2501][11];

double solve(int pos, int num)
{
    if (num > K) {
        return -1e9;
    }

    if (pos == N) {
        return 0.0;
    }

    double& ret = cache[pos][num];
    if (ret >= 0.0) {
        return ret;
    }

    double p = 1.0;
    double np = 0;
    ret = 0.0;
    for (int i=pos; i < N; i++) {
        p *= (1.0 - a[i]);
        np += p;

        ret = max(ret, np + solve(i + 1, num + 1));
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for (int i=0; i < N; i++) {
        cin >> a[i];
    }

    fill(&cache[0][0], &cache[N][0], -1.0);
    cout.precision(9);
    cout << fixed << solve(0, 0) << endl;

    return 0;
}
