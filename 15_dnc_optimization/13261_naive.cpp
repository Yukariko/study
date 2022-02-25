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
	int L, G;
	cin >> L >> G;

	vector<int> a(L);
	for (int& n : a) cin >> n;

	vector<ll> sum(L + 1);
	for (int i=1; i <= L; i++) sum[i] = sum[i-1] + a[i-1];

	auto C = [&](int i, int j) {
		return 1LL * (j - i + 1) * (sum[j+1] - sum[i]);
	};

	vector<vector<ll>> d(G, vector<ll>(L));
	for (int i=0; i < L; i++) {
		d[0][i] = C(0, i);
	}
	for (int i=1; i < G; i++) {
		for (int j=0; j < L; j++) {
			d[i][j] = d[i-1][j];
			for (int k=0; k < j; k++) {
				d[i][j] = min(d[i][j], d[i-1][k] + C(k+1, j));
			}
		}
	}

	cout << d[G-1][L-1] << endl;

	return 0;
}
