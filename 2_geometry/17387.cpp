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

	Point operator-(const Point& p) const
	{
		return {x - p.x, y - p.y};
	}

	ll operator*(const Point& p) const
	{
		return x * p.y - y * p.x;
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
};

ll ccw(const Point& a, const Point& b, const Point& c)
{
	ll res = (b - a) * (c - a);
	return res? res / abs(res): 0;
}

bool lineIntersection(Point a, Point b, Point c, Point d)
{
	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return !(d < a || b < c);
	}

	return ab <= 0 && cd <= 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

	vector<Point> a(4);
	for (auto& p : a)
		cin >> p.x >> p.y;

	cout << lineIntersection(a[0], a[1], a[2], a[3]) << endl;
    return 0;
}
