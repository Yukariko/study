#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N;
int a[51];
vector<int> t[51];
int cache[51];

int solve(int u)
{
	if (t[u].empty()) {
		return 0;
	}

	int& ret = cache[u];
	if (ret != -1) {
		return ret;
	}

	vector<int> times;
	for (int v : t[u]) {
		times.push_back(solve(v));
	}
	sort(times.begin(), times.end());

	ret = 0;
	int rem = t[u].size();
	for (int time : times) {
		ret = max(ret, time + rem);
		rem--;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cin >> a[0];
	for (int i=1; i < N; i++) {
		cin >> a[i];
		t[a[i]].push_back(i);
	}

	cout << solve(0) << endl;

	return 0;
}
