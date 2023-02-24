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
	int N, S;
	cin >> N >> S;

	vector<pair<int, int>> a(N);
	for (auto& [H, C] : a) {
		cin >> H >> C;
	}

	sort(a.begin(), a.end());

	vector<int> d(N);
	if (a[0].first >= S) {
		d[0] = a[0].second;
	}

	for (int i=1, j=0; i < N; i++) {
		while (a[j].first + S <= a[i].first) j++;
		j--;
		if (j < 0) {
			j = 0;
			d[i] = max(d[i-1], a[i].second);
		} else {
			d[i] = max(d[i-1], d[j] + a[i].second);
		}

	}

	cout << d[N-1] << endl;

	return 0;
}
