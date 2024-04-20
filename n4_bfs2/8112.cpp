#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (N == 1) {
            cout << 1 << endl;
            continue;
        }

        vector<bool> visited(N);
        vector<int> prev(N);
        queue<int> q;
        visited[1] = true;
        prev[1] = 0;
        q.emplace(1);

        bool found = false;
        while (!q.empty()) {
            auto n = q.front();
            q.pop();

            if (n == 0) {
                found = true;
                break;
            }

            int next = n * 10 % N;
            if (!visited[next]) {
                visited[next] = true;
                prev[next] = n;
                q.emplace(next);
            }

            next = (n * 10 + 1) % N;
            if (!visited[next]) {
                visited[next] = true;
                prev[next] = n;
                q.emplace(next);
            }
        }

        if (!found) {
            cout << "BRAK" << endl;
        } else {
            string res;
            int cur = 0;
            while (prev[cur] != -1) {
                if (prev[cur] * 10 % N == cur) {
                    res += '0';
                } else {
                    res += '1';
                }
                int tmp = prev[cur];
                prev[cur] = -1;
                cur = tmp;
            }
            reverse(res.begin(), res.end());
            cout << res << endl;
        }
    }

    return 0;
}
