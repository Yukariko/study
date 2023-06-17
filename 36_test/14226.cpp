#include <iostream>
#include <queue>
#include <vector>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<bool>> visited(N, vector<bool>(2 * N + 1));
    queue<pair<int, int>> q;
    visited[0][1] = true;
    q.emplace(0, 1);

    auto check_and_push = [&](int clipped, int num) {
        if (!visited[clipped][num]) {
            visited[clipped][num] = true;
            q.emplace(clipped, num);
        }
    };

    int ans = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [clipped, num] = q.front();
            q.pop();

            if (num == N) {
                cout << ans << endl;
                return 0;
            }

            if (num < N) {
                check_and_push(num, num);
            }

            if (clipped > 0 && num < N) {
                check_and_push(clipped, num + clipped);
            }

            if (num > 1) {
                check_and_push(clipped, num - 1);
            }
        }
        ans++;
    }


	return 0;
}
