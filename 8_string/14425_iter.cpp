#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

template <char tok = 'a'>
struct Trie {
    struct Node {
        vector<int> child = vector<int>(26);
        bool end = false;
    };
    vector<Node> node = vector<Node>(1);

    void insert(const char *s)
    {
        int ref = 0;
        for (int i=0; s[i]; i++) {
            int idx = s[i] - tok;
            auto& next = node[ref].child[idx];
            if (next == 0) {
                next = node.size();
                node.emplace_back(Node());
            }
            ref = next;
        }
        node[ref].end = true;
    }

    bool find(const char *s)
    {
        int ref = 0;
        for (int i=0; s[i]; i++) {
            int idx = s[i] - tok;
            auto& next = node[ref].child[idx];
            if (next == 0)
                return false;
            ref = next;
        }
        return node[ref].end;
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
