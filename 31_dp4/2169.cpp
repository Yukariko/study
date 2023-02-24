#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, M;
int a[1001][1001];

bool visited[1001][1001][2];
int cache[1001][1001][2];

int solve(int y, int x, int d)
{
	if (y == N-1 && x == M-1) {
		return a[y][x];
	}

	int& ret = cache[y][x][d];
	if (visited[y][x][d]) {
		return ret;
	}
	visited[y][x][d] = true;
	ret = -1e9;
	if (y < N) {
		ret = max(solve(y + 1, x, 0), solve(y + 1, x, 1));
	}
	if (d == 0 && x > 0) {
		ret = max(ret, solve(y, x - 1, 0));
	}
	if (d == 1 && x < M - 1) {
		ret = max(ret, solve(y, x + 1, 1));
	}
	ret += a[y][x];

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	for (int i=0; i < N; i++) {
		for (int j=0; j < M; j++) {
			cin >> a[i][j];
		}
	}

	cout << solve(0, 0, 1) << endl;

	return 0;
}
