#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

template <char tok = 'a'>
struct Trie {
    array<Trie *, 26> nodes = {};
    bool end = false;

    void insert(const char *s)
    {
        end = true;
        if (*s == '\0') { return; }
        Trie * &next = nodes[*s - tok];
        if (next == nullptr) next = new Trie;
        next->insert(s + 1);
    }

    bool find(const char *s)
    {
        if (*s == '\0') { return end; }
        Trie * &next = nodes[*s - tok];
        if (next == nullptr) return false;
        return next->find(s + 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    Trie trie;
    for (int i=0; i < N; i++) {
        string s;
        cin >> s;
        trie.insert(s.c_str());
    }

    int ans = 0;
    for (int i=0; i < M; i++) {
        string s;
        cin >> s;
        ans += trie.find(s.c_str());
    }

    cout << ans << endl;

    return 0;
}
