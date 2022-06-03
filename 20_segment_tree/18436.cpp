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

void build()
{
	for (int i=N-1; i > 0; i--) {
		t[i] = t[i * 2] + t[i * 2 + 1];
	}
}

void modify(int pos, int val)
{
	for (t[pos += N] = val; pos > 1; pos /= 2) {
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
	for (int i=0; i < N; i++) {
		cin >> t[i + N];
		t[i + N] %= 2;
	}

	build();

	int Q;
	cin >> Q;

	while (Q--) {
		int o, l, r;
		cin >> o >> l >> r;

		if (o == 1) {
			modify(l - 1, r % 2);
		} else if (o == 2) {
			cout << r - l + 1 - query(l - 1, r) << endl;
		} else {
			cout << query(l - 1, r) << endl;
		}
	}

	return 0;
}
