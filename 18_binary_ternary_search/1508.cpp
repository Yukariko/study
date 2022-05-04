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
	int N, M, K;
	cin >> N >> M >> K;

	if (M == 0) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> a(K);
	for (int& n : a) cin >> n;

	auto inplace = [&](int dist) {
		int cnt = 1;
		int sum = 0;
		for (int i=1; i < K; i++) {
			int diff = a[i] - a[i-1];
			sum += diff;
			if (sum >= dist) {
				cnt++;
				sum = 0;
			}
		}
		return cnt >= M;
	};

	int lo = 1, hi = 1000000;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (inplace(mid)) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	int sum = 0;
	int dist = hi;
	int cnt = 1;
	cout << 1;
	for (int i=1; i < K; i++) {
		int diff = a[i] - a[i-1];
		sum += diff;
		if (cnt < M && sum >= dist) {
			sum = 0;
			cnt++;
			cout << 1;
		} else {
			cout << 0;
		}
	}

	cout << endl;

	return 0;
}
