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

    vector<vector<int>> a(N, vector<int>(N));
    for (auto& v : a) {
        for (auto& n : v) {
            cin >> n;
        }
    }

    priority_queue<int> pq;
    for (int i=0; i < N; i++) {
        pq.push(-a[N-1][i]);
    }

    for (int i=N-2; i >= 0; i--) {
        for (int j=0; j < N; j++) {
            if (-pq.top() < a[i][j]) {
                pq.pop();
                pq.push(-a[i][j]);
            }
        }
    }

    cout << -pq.top() << endl;

    return 0;
}
