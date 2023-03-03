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
	int N;
	cin >> N;

	vector<int> a(N);
	for (int& n : a) {
		cin >> n;
	}

	int M;
	cin >> M;

	vector<vector<int>> cache(N, vector<int>(3));
	int sum = 0;
	for (int i=0; i < M - 1; i++) {
		sum += a[i];
	}

	for (int i=M - 1; i < N; i++) {
		sum += a[i];
		cache[i][0] = max(cache[i-1][0], sum);
		if (i >= M) {
			cache[i][1] = max(cache[i-1][1], sum + cache[i-M][0]);
			if (i >= M * 2) {
				cache[i][2] = max(cache[i-1][2], sum + cache[i-M][1]);
			}
		}
		sum -= a[i-M+1];
	}

	cout << cache[N-1][2] << endl;

	return 0;
}
