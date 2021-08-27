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

/*
 * Px= (x1*y2 - y1*x2)*(x3-x4) - (x1-x2)*(x3*y4 - y3*x4)
 * Py= (x1*y2 - y1*x2)*(y3-y4) - (y1-y2)*(x3*y4 - y3*x4)
 * p = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4)
 */
#if 0
	ll p = ((a - b) * (c - d));
	Point t = {a * b, c * d};
	Point tx = {a.x - b.x, c.x - d.x};
	Point ty = {a.y - b.y, c.y - d.y};
	r = { t * tx, t * ty};
	r = r / p;
#elif 0
	r = a + (b - a) * ((c - a) * (d - c)) / ((b - a) * (d - c));
#else
	Point vba = a - b;
	Point vdc = c - d;
	r = vdc * (a * b) - vba * (c * d);
	r = r / (vba * vdc);
#endif
	return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cout << fixed;
	cout.precision(10);

	vector<Point> a(4);
	for (auto& p : a)
		cin >> p.x >> p.y;

	const ll inf = 1e9;
	Point p = { inf, inf };
	bool intersect = lineIntersection(a[0], a[1], a[2], a[3], p);
	if (intersect) {
		cout << 1 << endl;
		if (!isnan(p.rx)) cout << p.rx << " " << p.ry << endl;
		else if (p.x != inf) cout << p.x << " " << p.y << endl;
	} else {
		cout << 0 << endl;
	}
    return 0;
}
