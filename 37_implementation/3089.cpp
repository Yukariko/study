#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> xs(200000), ys(200000);
    for (int i=0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        xs[y + 100000].push_back(x);
        ys[x + 100000].push_back(y);
    }

    for (int i=0; i < 200000; i++) {
        if (xs[i].size() > 1) {
            sort(xs[i].begin(), xs[i].end());
        }
        if (ys[i].size() > 1) {
            sort(ys[i].begin(), ys[i].end());
        }
    }

    auto find_vert = [&](int x, int y) {
        return lower_bound(ys[x + 100000].begin(), ys[x + 100000].end(), y);
    };

    auto find_hor = [&](int x, int y) {
        return lower_bound(xs[y + 100000].begin(), xs[y + 100000].end(), x);
    };
    string ops;
    cin >> ops;
    int x = 0, y = 0;
    for (int i=0; i < M; i++) {
        switch (ops[i]) {
        case 'L': x = *--find_hor(x, y); break;
        case 'R': x = *++find_hor(x, y); break;
        case 'U': y = *++find_vert(x, y); break;
        case 'D': y = *--find_vert(x, y); break;
        }
    }

    cout << x << " " << y << endl;

	return 0;
}
