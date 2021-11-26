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
    Trie *fail_node = nullptr;
    bool end = false;

    void insert(const char *s)
    {
        if (*s == '\0') { end = true; return; }
        Trie * &next = nodes[*s - tok];
        if (next == nullptr) next = new Trie;
        next->insert(s + 1);
    }

    bool find(const char *s)
    {
        if (end) return true;
        if (*s == '\0') return false;
        int idx = *s - tok;
        Trie * &next = nodes[idx];
        if (next == nullptr) return find_fail_node(this, idx)->find(s + 1);
        return next->find(s + 1);
    }

    static Trie * find_fail_node(Trie *node, int idx)
    {
        Trie *tmp = node->fail_node;
        while (tmp->fail_node != tmp && tmp->nodes[idx] == nullptr)
            tmp = tmp->fail_node;
        if (tmp->nodes[idx] != nullptr)
            tmp = tmp->nodes[idx];
        return tmp;
    }

    static void build_failure_func(Trie * root)
    {
        queue<Trie *> q;
        root->fail_node = root;
        for (int i=0; i < 26; i++) {
            if (root->nodes[i] == nullptr) continue;
            root->nodes[i]->fail_node = root;
            q.push(root->nodes[i]);
        }

        while (!q.empty()) {
            Trie * node = q.front();
            q.pop();

            for (int i=0; i < 26; i++) {
                if (node->nodes[i] == nullptr) continue;
                node->nodes[i]->fail_node = find_fail_node(node, i);
                q.push(node->nodes[i]);
            }
            node->end |= node->fail_node->end;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    Trie trie;

    int N, M;
    cin >> N;

    for (int i=0; i < N; i++) {
        string s;
        cin >> s;
        trie.insert(s.c_str());
    }

    Trie<'a'>::build_failure_func(&trie);

    cin >> M;
    for (int i=0; i < M; i++) {
        string s;
        cin >> s;
        if (trie.find(s.c_str()))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
