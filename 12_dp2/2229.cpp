#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N;
int a[1001];
int cache[1001];

int solve(int pos)
{
    int& ret = cache[pos];
    if (ret != -1) {
        return ret;
    }
    ret = 0;

    int min_point = a[pos], max_point = a[pos];
    for (int i=pos; i < N; i++) {
        min_point = min(min_point, a[i]);
        max_point = max(max_point, a[i]);
        ret = max(ret, max_point - min_point + solve(i + 1));
    }
    return ret;
}

int iterative()
{
    for (int i=0; i < N; i++) {
        cache[i] = 0;
        int min_point = a[i], max_point = a[i];
        for (int j=i; j >= 0; j--) {
            cache[i] = max(cache[i], max_point - min_point + cache[j]);
            min_point = min(min_point, a[j]);
            max_point = max(max_point, a[j]);
        }
        cache[i] = max(cache[i], max_point - min_point);
    }
    return cache[N-1];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    memset(cache, -1, sizeof(cache));

    cin >> N;

    for (int i=0; i < N; i++) {
        cin >> a[i];
    }

    cout << iterative() << endl;
    //cout << solve(0) << endl;

    return 0;
}
