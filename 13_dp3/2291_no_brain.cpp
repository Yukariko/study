#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, M, K;
int selected[11];
int cache[221][11][221];

int solve(int pos, int sum, int num)
{
    if (sum > M) {
        return 0;
    }
    if (pos == N) {
        if (sum == M && --K == 0) {
            for (int i=0; i < N; i++) {
                cout << selected[i] << " ";
            }
            cout << endl;
            exit(0);
        }
        return sum == M;
    }

    int& ret = cache[sum][pos][num];
    if (ret != -1 && ret < K) {
        K -= ret;
        return ret;
    }

    ret = 0;
    for (int i=num; i <= M - sum; i++) {
        selected[pos] = i;
        ret += solve(pos + 1, sum + i, i);
    }

    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K;
    memset(cache, -1, sizeof(cache));
    solve(0, 0, 1);
    return 0;
}
