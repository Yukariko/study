#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int dy[] = { -1, -1, 0, 0, 1, 1 };
const int dx[] = { 0, 1, -1, 1, -1, 0 };

const int red = 1;
const int black = 2;
int N;
char a[51][51];
int colors[51][51];

int dfs(int y, int x, int c)
{
    int nc = c == red? black: red;
    int res = 1;
    for (int d=0; d < 6; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] != 'X') continue;
        if (colors[ny][nx] == c) {
            return 3;
        }
        if (!colors[ny][nx]) {
            colors[ny][nx] = nc;
            if (dfs(ny, nx, nc) == 3) {
                return 3;
            }
        }
        res = 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int i=0; i < N; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            if (a[i][j] == 'X' && !colors[i][j]) {
                colors[i][j] = red;
                ans = max(ans, dfs(i, j, red));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
