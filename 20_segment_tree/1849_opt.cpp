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

int kth(int k)
{
	int i = 1;
	int m = N;
	while (i < N) {
		m /= 2;
		if (m - t[i * 2] > k) {
			i *= 2;
		} else {
			k -= m - t[i * 2];
			i = i * 2 + 1;
		}
	}
	return i - N;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int _N;
	cin >> _N;
	N = 1;
	while (N < _N) {
		N *= 2;
	}
	vector<int> a(_N);
	for (int i=1; i <= _N; i++) {
		int n;
		cin >> n;
		int pos = kth(n);
		a[pos] = i;
		modify(pos, 1);
	}

	for (int n : a) {
		cout << n << endl;
	}

	return 0;
}
