#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct Point
{
	ll x, y;
	double rx = nan(""), ry = nan("");

	Point() {}
	Point(ll x, ll y) : x(x), y(y) {}

	Point operator-(const Point& p) const
	{
		return {x - p.x, y - p.y};
	}

	ll operator*(const Point& p) const
	{
		return x * p.y - y * p.x;
	}

	Point operator*(ll c) const
	{
		return {x * c, y * c};
	}

	Point operator/(double p) const
	{
		Point res;
		res.rx = x / p;
		res.ry = y / p;
		return res;
	}

	bool operator>(const Point& p) const
	{
		if (x != p.x) return x > p.x;
		return y > p.y;
	}

	bool operator<(const Point& p) const
	{
		return p > *this;
	}

	bool operator==(const Point& p) const
	{
		return x == p.x && y == p.y;
	}
};

ll ccw(const Point& a, const Point& b, const Point& c)
{
	ll res = (b - a) * (c - a);
	return res? res / abs(res): 0;
}

bool lineIntersection(Point a, Point b, Point c, Point d, Point& r)
{
	ll abc = ccw(a, b, c);
	ll abd = ccw(a, b, d);
	ll cda = ccw(c, d, a);
	ll cdb = ccw(c, d, b);

	if ((abc | abd | cda | cdb) == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (d < a || b < c) return false;
		if (a == d) r = a;
		if (b == c) r = b;
		return true;
	}

	if (abc * abd > 0 || cda * cdb > 0) return false;

	Point vba = a - b;
	Point vdc = c - d;
	r = vdc * (a * b) - vba * (c * d);
	r = r / (vba * vdc);
	return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

#if 0
	int N;
	cin >> N;
	vector<Point> a(N);
	for (auto& p : a)
		cin >> p.x >> p.y;

	int base = 0;
	for (int i=1; i < N; i++)
		if (a[i].y < a[base].y)
			base = i;

	swap(a[0], a[base]);
	sort(next(a.begin()), a.end(), [&](const auto& p, const auto& q) {
		Point dp = p - a[0];
		Point dq = q - a[0];
		if (dp.y * dq.x != dp.x * dq.y)
			return dp.y * dq.x < dp.x * dq.y;
		return p < q;
	});
#else
	int N;
	cin >> N;
	vector<Point> a(N);
	for (auto& p : a)
		cin >> p.y >> p.x;

	int base = distance(a.begin(), min_element(a.begin(), a.end()));

	swap(a[0], a[base]);
	sort(next(a.begin()), a.end(), [&](const auto& p, const auto& q) {
		Point dp = p - a[0];
		Point dq = q - a[0];
		if (dp.y * dq.x != dp.x * dq.y)
			return dp.y * dq.x < dp.x * dq.y;
        return p < q;
	});
#endif

	stack<int> st;
	st.push(0); st.push(1);

	for (int i=2; i < N; i++) {
		while (st.size() > 1) {
			int q = st.top();
			st.pop();
			int p = st.top();

			if (ccw(a[p], a[q], a[i]) > 0) {
				st.push(q);
				break;
			}
		}
		st.push(i);
	}

	cout << st.size() << endl;
	return 0;
}
