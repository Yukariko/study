#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct station
{
	int pos;
	int cap;

	station() {}
	station(int pos, int cap) : pos(pos), cap(cap) {}

	bool operator<(const station& rhs) const
	{
		return pos < rhs.pos;
	}

};

/* old style */
struct comp
{
	bool operator()(const station& p, const station& q)
	{
		return p.cap < q.cap;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;

	vector<station> a(N);
	for (auto& [dist, fuel] : a) {
		cin >> dist >> fuel;
	}
	sort(a.begin(), a.end());

	int L, P;
	cin >> L >> P;

	a.emplace_back(L, 0);


	//priority_queue<station, vector<station>, comp> pq;

	auto cmp = [](const station& p, const station& q) {
		return p.cap < q.cap;
	};
	priority_queue<station, vector<station>, decltype(cmp)> pq(cmp);

	int ans = 0;
	int pos = 0;
	for (auto& [dist, fuel] : a) {
		int required = dist - pos;

		while (!pq.empty() && P < required) {
			P += pq.top().cap;
			pq.pop();
			ans++;
		}

		if (P < required) {
			cout << -1 << endl;
			return 0;
		}

		P -= required;
		pq.emplace(dist, fuel);
		pos = dist;
	}

	cout << ans << endl;

	return 0;
}
