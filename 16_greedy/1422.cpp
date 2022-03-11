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
	int K, N;
	cin >> K >> N;
	vector<int> a(K);
	for (int& n : a) cin >> n;
	sort(a.begin(), a.end());

	vector<pair<string, int>> b;
	for (int i=0; i < K; i++) {
		b.emplace_back(to_string(a[i]), i != K-1? 1 : N - i);
	}

	sort(b.begin(), b.end(), [](auto& p, auto& q) {
		return p.first + q.first > q.first + p.first;
	});

	for (auto& [s, c] : b) {
		while (c--) {
			cout << s;
		}
	}

	cout << endl;

	return 0;
}
