#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, M, K;
char str[201];
int cache[101][101];

int solve(int pos, int acnt, int bcnt)
{
    if (acnt > N || bcnt > M) {
        return 0;
    }
    if (pos == N + M) {
        if (--K == 0) {
            cout << str << endl;
            exit(0);
        }
        return 1;
    }

    int& ret = cache[acnt][bcnt];
    if (ret != -1 && ret < K) {
        K -= ret;
        return ret;
    }

    str[pos] = 'a';
    ret = solve(pos + 1, acnt + 1, bcnt);
    str[pos] = 'z';
    ret += solve(pos + 1, acnt, bcnt + 1);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K;
    memset(cache, -1, sizeof(cache));
    solve(0, 0, 0);
    cout << -1 << endl;
    return 0;
}
