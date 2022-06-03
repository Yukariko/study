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
	vector<int> a(N);
	for (int i=1; i <= N; i++) {
		int n;
		cin >> n;
		int l = n, r = N-1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (mid - query(0, mid + 1) < n) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		a[l] = i;
		modify(l, 1);
	}

	for (int n : a) {
		cout << n << endl;
	}

	return 0;
}
