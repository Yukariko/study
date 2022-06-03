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
	vector<int> idx(N + 1);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
		idx[a[i]] = i;
	}


	int l = 1, r = N;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			cout << idx[l] - query(0, idx[l]) << endl;
			modify(idx[l], 1);
			l++;
		} else {
			cout << N - 1 - idx[r] - query(idx[r], N) << endl;
			modify(idx[r], 1);
			r--;
		}
	}


	return 0;
}
