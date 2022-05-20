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

	vector<stack<int>> a(6);

	int N, P;
	cin >> N >> P;

	int ans = 0;
	while (N--) {
		int line, no;
		cin >> line >> no;

		auto& st = a[line];
		while (!st.empty() && st.top() > no) {
			st.pop();
			ans++;
		}
		if (st.empty() || st.top() != no) {
			st.push(no);
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
