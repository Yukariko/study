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

	int T;
	cin >> T;

	while (T--) {
		vector<Point> a(4);
		for (auto& p : a)
			cin >> p.x >> p.y;

		vector<Point> rect;
		rect.push_back(a[2]);
		rect.emplace_back(a[3].x, a[2].y);
		rect.push_back(a[3]);
		rect.emplace_back(a[2].x, a[3].y);

		bool find = false;
		for (int i=0; i < 4; i++) {
			Point tmp;
			if (lineIntersection(rect[i], rect[(i + 1) % 4], a[0], a[1], tmp)) {
				find = true;
				break;
			}
		}

		auto inRect = [&](auto l, auto r, auto p) {
			if (l.x > r.x) swap(l.x, r.x);
			if (l.y > r.y) swap(l.y, r.y);
			return l.x < p.x && p.x < r.x && l.y < p.y && p.y < r.y;
		};

		if (find) cout << "T" << endl;
		else if (inRect(a[2], a[3], a[0]) && inRect(a[2], a[3], a[1])) cout << "T" << endl;
		else cout << "F" << endl;
	}
	return 0;
}
