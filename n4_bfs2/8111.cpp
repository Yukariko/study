#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
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

        vector<bool> visited(N);
        queue<pair<int, string>> q;
        visited[1] = true;
        q.emplace(1, "1");

        string ans = "";
        while (!q.empty()) {
            auto [n, m] = q.front();
            q.pop();

            if (n == 0) {
                ans = m;
                break;
            }

            int next = n * 10 % N;
            if (!visited[next]) {
                visited[next] = true;
                q.emplace(next, m + '0');
            }

            next = (n * 10 + 1) % N;
            if (!visited[next]) {
                visited[next] = true;
                q.emplace(next, m + '1');
            }
        }

        if (ans == "") {
            cout << "BRAK" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}
