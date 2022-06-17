#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MAX_N = 100000;

int N;
int a[MAX_N];
int t[MAX_N * 2];

int imax(int l, int r)
{
	return a[l] < a[r]? r: l;
}

void build()
{
	for (int i = N - 1; i > 0; i--) {
		t[i] = imax(t[i * 2], t[i * 2 + 1]);
	}
}

void modify(int pos, int val)
{
	a[pos] = val;
	for (pos += N; pos > 1; pos /= 2) {
		t[pos / 2] = imax(t[pos], t[pos ^ 1]);
	}
}

int query(int l, int r)
{
	int ans = l;
	for (l += N, r += N; l < r; l /= 2, r /= 2) {
		if (l & 1) ans = imax(ans, t[l++]);
		if (r & 1) ans = imax(ans, t[--r]);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;

	for (int i=0; i < N; i++) {
		cin >> a[i];
		t[N + i] = i;
	}

	build();

	int Q;
	cin >> Q;

	while (Q--) {
		int O;
		cin >> O;

		if (O == 1) {
			int I, V;
			cin >> I >> V;
			modify(I - 1, V);
		} else {
			int L, R;
			cin >> L >> R;

			int max1 = query(L - 1, R);
			int max2 = max1 == L - 1? R - 1: L - 1;
			if (max1 != L - 1) max2 = imax(max2, query(L - 1, max1));
			if (max1 != R - 1) max2 = imax(max2, query(max1 + 1, R));

			cout << a[max1] + a[max2] << endl;
		}
	}

	return 0;
}
