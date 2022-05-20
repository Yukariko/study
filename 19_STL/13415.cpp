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
	for(int& n : a) {
		cin >> n;
	}

	int K;
	cin >> K;

	deque<pair<int, bool>> dq;
	K *= 2;
	bool asc = false;
	while (K--) {
		int A;
		cin >> A;
		asc = !asc;

		while (!dq.empty() && dq.front().first <= A) {
			dq.pop_front();
		}
		dq.emplace_front(A, asc);
	}

	sort(a.begin(), a.begin() + dq.back().first);

	vector<int> ans(N);
	int lo = 0, hi = N-1;
	asc = true;
	for (int i=N; i >= 1; i--) {
		if (!dq.empty() && dq.back().first == i) {
			auto& [n, next_asc] = dq.back();
			dq.pop_back();
			asc = next_asc;
		}
		if (asc) {
			ans[i-1] = a[hi--];
		} else {
			ans[i-1] = a[lo++];
		}

	}

	for (int n : ans) {
		cout << n << " ";
	}
	cout << endl;

	return 0;
}
