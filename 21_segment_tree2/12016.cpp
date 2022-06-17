#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MAX_N = 100000;

int N;
int t[MAX_N * 2];

void update(int pos, int val)
{
	for (t[pos += N] += val; pos > 1; pos /= 2) {
		t[pos / 2] = t[pos] + t[pos ^ 1];
	}
}

int query(int l, int r)
{
	int sum = 0;
	for (l += N, r += N; l < r; l /= 2, r /= 2) {
		if (l & 1) sum += t[l++];
		if (r & 1) sum += t[--r];
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;

	vector<pair<int, int>> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end(), [](auto& p, auto& q) {
		if (p.first != q.first) return p.first < q.first;
		return p.second > q.second;
	});

	vector<ll> ans(N);

	int num = N;
	int bef = 0;
	ll sum = 0, next_sum = 0;
	for (auto& [t, i] : a) {
		int diff = t - bef;
		if (diff > 0) {
			sum = next_sum;
			sum += 1LL * (diff - 1) * num;
			next_sum +=  1LL * diff * num;
			bef = t;
		}
		update(i, 1);

		ans[i] = sum + i + 1 - query(0, i);
		num--;
	}

	for (ll n : ans) cout << n << endl;
	return 0;
}
