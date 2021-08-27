#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct Point
{
	int x, y;

	Point operator-(const Point& p) const
	{
		return {x - p.x, y - p.y};
	}

	int operator*(const Point& p) const
	{
		return x * p.y - y * p.x;
	}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

	vector<Point> a(3);
	for (auto& p : a)
		cin >> p.x >> p.y;

	int ccw = (a[1] - a[0]) * (a[2] - a[0]);
	if (ccw) ccw /= abs(ccw);
	cout << ccw << endl;
    return 0;
}
