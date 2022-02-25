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
	cin >> N >> K;

	vector<int> a(N);
	for (int& n : a) cin >> n;

	vector<int> d_cur(N), d_bef(N);

	d_bef[0] = a[0];
	for (int i=1; i < N; i++) {
		d_bef[i] = d_bef[i-1] | a[i];
	}

	for (int i=1; i < K; i++) {
		for (int j=0; j < N; j++) {
			d_cur[j] = d_bef[j];
			int sum = 0;
			for (int k=j; k >= 1; k--) {
				sum |= a[k];
				d_cur[j] = max(d_cur[j], d_bef[k-1] + sum);
			}
		}
		swap(d_bef, d_cur);
	}

	cout << d_bef[N-1] << endl;

	return 0;
}
