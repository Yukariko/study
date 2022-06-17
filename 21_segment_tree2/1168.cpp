#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MAX_N = 1024 * 128;

int N;
int t[MAX_N * 2];

void build()
{
	for (int i = N - 1; i > 0; i--) {
		t[i] = t[i * 2] + t[i * 2 + 1];
	}
}

void update(int pos, int val)
{
	for (t[pos += N] += val; pos > 1; pos /= 2) {
		t[pos / 2] = t[pos] + t[pos ^ 1];
	}
}

int kth(int k)
{
	int i;
	for (i=1; i < N;) {
		if (t[i * 2] > k) {
			i *= 2;
		} else {
			k -= t[i * 2];
			i = i * 2 + 1;
		}
	}
	return i - N;
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

	int _N;
	int K;
	cin >> _N >> K;

	N = 1;
	while (N < _N) N *= 2;

	fill(&t[N], &t[N + _N], 1);
	build();

	cout << "<";

	int idx = 0;
	for (int i=0; i < _N; i++) {
		int cnt = query(idx, _N);
		int ord = (K - 1) % (_N - i) + 1;
		if (cnt >= ord) {
			int l = query(0, idx);
			idx = kth(l + ord - 1);
		} else {
			idx = kth(ord - cnt - 1);
		}

		update(idx, -1);
		int victim = idx + 1;
		if (i != _N-1)
			cout << victim << ", ";
		else
			cout << victim;
	}
	cout << ">" << endl;

	return 0;
}
