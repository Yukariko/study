#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

class A
{
public:
	int n = 1;
	A() {
		cout << "default" << endl;
	}

	A(const A&& a) {
		cout << "r-value" << endl;
	}

	A(const A& a) {
		cout << "reference" << endl;
		n = a.n;
	}

	A operator=(const A&& a) {
		cout << "operator==" << endl;
		n = a.n;
		return *this;
	}

	A operator=(const A& a) {
		cout << "operator=" << endl;
		n = a.n;
		return *this;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	A a;
	A b = a;
	A c = A();
	A d = move(a);
	A e;
	e = a;
	e = A();

	return 0;
}
