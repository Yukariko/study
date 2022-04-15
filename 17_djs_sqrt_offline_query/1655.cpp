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

	int sz = sqrt(20000) + 1;
	vector<int> chunk(sz), num(20001);

	for (int i=0; i < N; i++) {
		int n;
		cin >> n;
		num[n + 10000]++;
		chunk[(n + 10000) / sz]++;

		int mid = i / 2 + 1;
		int cnt = 0;
		int j;
		for (j=0; j < sz && cnt + chunk[j] < mid; j++) {
			cnt += chunk[j];
		}

		j *= sz;

		while (cnt + num[j] < mid) {
			cnt += num[j];
			j++;
		}

		cout << j - 10000 << endl;
	}



	return 0;
}
