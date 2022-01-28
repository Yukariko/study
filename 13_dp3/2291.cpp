#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, M, K;
int cache[221][11];

int solve(int pos, int sum)
{
    int& ret = cache[sum][pos];
    if (ret != -1) {
        return ret;
    }

    if (sum < pos) {
        return ret = 0;
    }

    if (pos == 0) {
        return ret = sum == 0;
    }

    return ret = solve(pos, sum - pos) + solve(pos - 1, sum - 1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K;
    memset(cache, -1, sizeof(cache));
    solve(N, M);

    for (int i = 1; M--, N--;) {
        while (K > cache[M][N]) {
            K -= cache[M][N];
            M -= N + 1;
            i++;
        }
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
