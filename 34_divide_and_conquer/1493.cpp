#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int L, W, H;
int N;
pair<int, int> a[21];
bool possible = true;

int solve(int idx, ll l, ll w, ll h)
{
    if (l == 0 || w == 0 || h == 0) {
        return 0;
    }
    if (idx == -1) {
        possible = false;
        return -1;
    }

    int cl = 1 << a[idx].first;
    ll ml = min({l, w, h});
    if (cl > ml) {
        return solve(idx - 1, l, w, h);
    }

    int cc = a[idx].second;
    ll lc = l / cl;
    ll wc = w / cl;
    ll hc = h / cl;
    ll need_cnt = lc * wc * hc;
    ll cnt = min(1LL * cc, need_cnt);
    a[idx].second -= cnt;
    ll lenl = lc * cl;
    ll lenw = wc * cl;
    ll lenh = hc * cl;
    return cnt + solve(idx - 1, cl, cl, cl * (need_cnt - cnt)) + solve(idx - 1, l - lenl, w, h) + solve(idx - 1, lenl, w - lenw, lenh) + solve(idx - 1, lenl, w, h - lenh);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> L >> W >> H;
    cin >> N;
    for (int i=0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int ret = solve(N - 1, L, W, H);
    if (!possible) {
        cout << -1 << endl;
    } else {
        cout << ret << endl;
    }

	return 0;
}
