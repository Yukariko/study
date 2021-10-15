#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

int R, C;
char a[251][251];
bool visited[251][251];

pair<int, int> dfs(int y, int x)
{
    int sheeps = 0, wolves = 0;
    if (a[y][x] == 'o') sheeps++;
    else if (a[y][x] == 'v') wolves++;

    for (int d=0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C || a[ny][nx] == '#' || visited[ny][nx]) continue;
        visited[ny][nx] = true;
        auto [sheep, wolf] = dfs(ny, nx);
        sheeps += sheep;
        wolves += wolf;
    }
    return { sheeps, wolves };
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> R >> C;
    for (int i=0; i < R; i++) cin >> a[i];

    int safe_sheeps = 0, safe_wolves = 0;
    for (int i=0; i < R; i++) {
        for (int j=0; j < C; j++) {
            if (a[i][j] == '#' || visited[i][j]) continue;
            visited[i][j] = true;
            auto [sheeps, wolves] = dfs(i, j);
            if (sheeps > wolves) {
                safe_sheeps += sheeps;
            } else {
                safe_wolves += wolves;
            }
        }
    }

    cout << safe_sheeps << " " << safe_wolves << endl;
    return 0;
}
