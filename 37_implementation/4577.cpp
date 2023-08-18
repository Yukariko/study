#include <iostream>
#include <vector>
#include <map>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    map <char, pair<int, int>> op = {
        { 'U', { -1, 0 } },
        { 'L', { 0, -1 } },
        { 'R', { 0, 1 } },
        { 'D', { 1, 0 } },
    };
    int N, M;
    for (int tc=1; cin >> N >> M, N; tc++) {
        vector<string> a(N);
        for (auto& s : a) cin >> s;

        string ops;
        cin >> ops;

        int x, y;
        int boxes = 0;
        for (int i=0; i < N; i++) {
            for (int j=0; j < M; j++) {
                if (a[i][j] == 'w' || a[i][j] == 'W') {
                    y = i;
                    x = j;
                } else if (a[i][j] == 'b') {
                    boxes++;
                }
            }
        }

        for (int i=0; ops[i]; i++) {
            auto [dy, dx] = op[ops[i]];
            int ny = y + dy;
            int nx = x + dx;
            if (a[ny][nx] == '#') {
                continue;
            }
            if (a[ny][nx] == 'b' || a[ny][nx] == 'B') {
                int nny = y + dy * 2;
                int nnx = x + dx * 2;
                if (a[nny][nnx] != '.' && a[nny][nnx] != '+') {
                    continue;
                }
                if (a[ny][nx] == 'b' && a[nny][nnx] == '+') {
                    boxes--;
                } else if (a[ny][nx] == 'B' && a[nny][nnx] == '.') {
                    boxes++;
                }
                a[ny][nx] = a[ny][nx] == 'b'? 'w': 'W';
                a[nny][nnx] = a[nny][nnx] == '.'? 'b': 'B';
            } else {
                a[ny][nx] = a[ny][nx] == '.'? 'w': 'W';
            }
            a[y][x] = a[y][x] == 'w'? '.': '+';
            y = ny, x = nx;
            if (!boxes) {
                break;
            }
        }

        if (boxes) {
            cout << "Game " << tc << ": incomplete" << endl;
        } else {
            cout << "Game " << tc << ": complete" << endl;
        }

        for (int i=0; i < N; i++) {
            cout << a[i] << endl;
        }
    }

	return 0;
}
