#include <iostream>
#include <algorithm>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for (auto& n : a) {
        cin >> n;
    }

    int flip = a[0] == 1? 1 : 0;
    for (int i=1; i < N; i++) {
        if (a[i] == 1 && a[i - 1] == 0) {
            flip++;
        }
    }

    while (M--) {
        int O;
        cin >> O;

        if (O == 0) {
            cout << flip << endl;
        } else {
            int I;
            cin >> I;
            I--;
            if (a[I] == 1) {
                continue;
            }

            a[I] = 1;
            if ((I == 0 || a[I - 1] == 0) && (I == N - 1 || a[I + 1] == 0)) {
                flip++;
            } else if ((I > 0 && a[I - 1] == 1) && (I < N - 1 && a[I + 1] == 1)) {
                flip--;
            }
        }
    }

    return 0;
}
