#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string INF;

string cache[101];

string num_min(string& p, string&& q)
{
	if (p.size() != q.size()) {
		return p.size() < q.size()? p: q;
	}
	return min(p, q);
}

string solve(int n)
{
	if (n == 0) {
		return "";
	}
	string& ret = cache[n];
	if (!ret.empty()) {
		return ret;
	}

	ret = INF;
	for (int i=0; i < 10; i++) {
		if (cnt[i] <= n) {
			ret = num_min(ret, (char)(i + '0') + solve(n - cnt[i]));
		}
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i=0; i < 50; i++) {
		INF += '1';
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		string max_num;
		int tmp = N;
		if (tmp % 2) {
			max_num += '7';
			tmp -= 3;
		}
		while (tmp > 0) {
			max_num += '1';
			tmp -= 2;
		}

		string min_num = INF;
		for (int i=1; i <= 9; i++) {
			if (cnt[i] <= N) {
				min_num = num_min(min_num, (char)(i + '0') + solve(N - cnt[i]));
			}
		}
		cout << min_num << " " << max_num << endl;
	}

	return 0;
}
