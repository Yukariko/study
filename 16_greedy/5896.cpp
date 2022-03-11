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
	int N, K;
	ll M;
	cin >> N >> K >> M;

	vector<pair<int, int>> a(N);
	for (auto& [c, p] : a) {
		cin >> p >> c;
	}
	sort(a.begin(), a.end());

	priority_queue<int> pq;

	int ans = 0;
	for (int i=0; i < K; i++) {
		if (M >= a[i].first) {
			M -= a[i].first;
			ans++;
			pq.push(a[i].first - a[i].second);
		}
	}

	for (int i=K; i < N; i++) {
		if (!pq.empty() &&
				M + pq.top() - a[i].first >= 0 &&
				M + pq.top() - a[i].first > M - a[i].second) {
			M -= -pq.top() + a[i].first;
			pq.pop();
			ans++;
			pq.push(a[i].first - a[i].second);
		} else if (M >= a[i].second) {
			M -= a[i].second;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
