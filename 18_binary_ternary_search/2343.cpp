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
	int N, M;
	cin >> N >> M;

	vector<int> a(N);
	for (int& n : a) cin >> n;

	auto fit = [&](int sz) {
		int cnt = 0;
		int sum = 0;
		for (int n : a) {
			sum += n;
			if (sum > sz) {
				cnt++;
				sum = n;
			}
		}
		if (sum) {
			cnt++;
		}
		return cnt <= M;
	};

	int lo = *max_element(a.begin(), a.end()), hi = 1e9;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (fit(mid)) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << lo << endl;

	return 0;
}
